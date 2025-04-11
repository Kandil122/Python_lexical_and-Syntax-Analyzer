#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <fstream>
#include <optional>
#include <sstream>  // Fix: Added missing header for stringstream
using namespace std;

enum class TokenType {
    KEYWORD, IDENTIFIER, NUMBER, STRING, OPERATOR, DELIMITER,
    INDENT, DEDENT, NEWLINE, ENDOFFILE
};

struct Token {
    string lexeme;
    TokenType type;
    int line;
    int column;
};

struct LexicalError {
    string message;
    int line;
    int column;
};

class SymbolTable {
private:
    unordered_map<string, int> symbols;
    int current_id = 1;

public:
    int addIdentifier(const string& identifier, int line) {
        if (!symbols.count(identifier)) {
            symbols[identifier] = current_id++;
        }
        return symbols[identifier];
    }

    optional<int> lookup(const string& identifier) const {
        auto it = symbols.find(identifier);
        return it != symbols.end() ? optional<int>(it->second) : nullopt;
    }
};

class PythonLexer {
private:
    string source;
    size_t pos = 0;
    int line = 1;
    int column = 1;
    SymbolTable symbolTable;
    vector<Token> tokens;
    vector<LexicalError> errors;

    const unordered_set<string> keywords = {
        "False", "None", "True", "and", "as", "assert", "async", "await",
        "break", "class", "continue", "def", "del", "elif", "else", "except",
        "finally", "for", "from", "global", "if", "import", "in", "is",
        "lambda", "nonlocal", "not", "or", "pass", "raise", "return",
        "try", "while", "with", "yield"
    };

    char current() const { return pos < source.size() ? source[pos] : '\0'; }
    char peek() const { return pos + 1 < source.size() ? source[pos + 1] : '\0'; }

    void advance() {
        if (current() == '\n') {
            line++;
            column = 1;
        } else {
            column++;
        }
        pos++;
    }

    void addToken(const string& lexeme, TokenType type) {
        tokens.push_back({ lexeme, type, line, column - static_cast<int>(lexeme.length()) });
    }

    void addError(const string& message) {
        errors.push_back({ message, line, column });
    }

    bool isOperatorChar(char c) {
        static const string opChars = "+-*/%=&|<>!^~";
        return opChars.find(c) != string::npos;
    }

    bool isDelimiter(char c) {
        static const string delimiters = ":,;()[]{}@";
        return delimiters.find(c) != string::npos;
    }

    void processNumber() {
        string num;
        bool hasDot = false;
        bool valid = true;

        // Allow digits, a single dot, and valid underscores
        while (isdigit(current()) || current() == '.' || current() == '_') {
            if (current() == '.') {
                if (hasDot) break;
                hasDot = true;
            }
            num += current();
            advance();
        }

        // Check for invalid underscore placement
        if (num.front() == '_' || num.back() == '_' || num.find("") != string::npos) {
            addError("Invalid underscore placement in number: " + num);
            valid = false;
        }

        // Check for valid numeric suffix
        if (current() == 'j' || current() == 'J') {  // Complex numbers
            num += current();
            advance();
            addError("Complex number error: " + num);
            valid = false;
        }
        else if (isalpha(current())) {  // Invalid suffix after a number
            valid = false;
            string invalid = num;
            while (isalnum(current()) || current() == '_') {
                invalid += current();
                advance();
            }
            addError("Invalid identifier (identifiers can't start with a number): " + invalid);
        }

        if (valid) {
            addToken(num, TokenType::NUMBER);
        }
    }

    void processString(char quote) {
        string str;
        int startLine = line;
        int startColumn = column;
        advance(); // Skip the initial quote

        // Check for triple quotes
        bool isTriple = false;
        if (current() == quote && peek() == quote) {
            isTriple = true;
            advance(); // Skip second quote
            advance(); // Skip third quote
        }
        if (current() == '\\') {
            advance();

            if (current() != 'n' && current() != 't' && current() != '\\' && current() != '"' && current() != '\'') {
                addError("Invalid escape sequence: \\" + string(1, current()));
            }
        }

        if (isTriple) {
            // Process a triple-quoted string, which can include newlines.
            while (true) {
                if (current() == '\0') {
                    addError("Unterminated triple-quoted string starting at line " +
                             to_string(startLine) + " column " + to_string(startColumn));
                    return;
                }
                // Check if the next three characters match the closing triple quotes
                if (current() == quote && peek() == quote && (pos + 2 < source.size() && source[pos + 2] == quote)) {
                    advance(); // Skip first closing quote
                    advance(); // Skip second closing quote
                    advance(); // Skip third closing quote
                    break;
                }
                str += current();
                advance();
            }
            addToken(str, TokenType::STRING);
        } else {
            // Process a normal string literal that should not contain newlines
            while (current() != quote && current() != '\0') {
                if (current() == '\n') { // Unterminated error for standard strings
                    addError("Unterminated string literal starting at line " +
                             to_string(startLine) + " column " + to_string(startColumn));
                    // Optionally skip to end of line
                    while (current() != '\n' && current() != '\0') {
                        advance();
                    }
                    return;
                }
                if (current() == '\\') {
                    advance();
                    if (current() == '\0') break;
                }
                str += current();
                advance();
            }

            if (current() != quote) {
                addError("Unterminated string literal starting at line " +
                         to_string(startLine) + " column " + to_string(startColumn));
                return;
            }
            advance();  // Consume closing quote
            addToken(str, TokenType::STRING);
        }
    }

    void processIdentifier() {
        string ident;

        // Enhanced validation: identifiers must not start with a digit or an underscore followed by a digit.
        if (isdigit(current())) {
            string invalid;
            while (isalnum(current()) || current() == '_') {
                invalid += current();
                advance();
            }
            addError("Invalid identifier starts with digit: " + invalid);
            return;
        }

        // Check for underscores at the beginning followed by a digit (e.g., _9)
        if (current() == '_') {
            string invalid;
            invalid += current();
            advance();
            if (isdigit(current())) {
                invalid += current();
                advance();
                addError("Invalid number starts with _: " + invalid);
                return;
            }
        }

        // Process the valid identifier
        while (isalnum(current()) || current() == '_') {
            ident += current();
            advance();
        }

        if (keywords.count(ident)) {
            addToken(ident, TokenType::KEYWORD);
        } else {
            symbolTable.addIdentifier(ident, line);
            addToken(ident, TokenType::IDENTIFIER);
        }
    }

    void processOperator() {
        string op(1, current());
        const char next = peek();

        const vector<pair<char, char>> multiOps = {
            {'=', '='}, {'!', '='}, {'<', '='}, {'>', '='},
            {'+', '='}, {'-', '='}, {'*', '='}, {'/', '='},
            {'%', '='}, {'&', '&'}, {'|', '|'}, {'*', '*'},
            {'/', '/'}, {'-', '>'}
        };

        for (const auto& [c1, c2] : multiOps) {
            if (current() == c1 && next == c2) {
                op += c2;
                advance();
                break;
            }
        }

        advance();
        addToken(op, TokenType::OPERATOR);
    }

public:
    PythonLexer(const string& input) : source(input) {}

    pair<vector<Token>, vector<LexicalError>> tokenize() {
        while (current() != '\0') {
            if (current() == '\n') {
                addToken("\n", TokenType::NEWLINE);
                advance();
                continue;
            }
            else if (isspace(current())) {
                // Skip other whitespace characters (spaces, tabs)
                advance();
                continue;
            }
            else if (isdigit(current())) {
                processNumber();
                continue;
            }
            else if (isalpha(current()) || current() == '_') {
                processIdentifier();
                continue;
            }
            else if (current() == '"' || current() == '\'') {
                processString(current());
                continue;
            }
            else if (isOperatorChar(current())) {
                processOperator();
                continue;
            }
            else if (isDelimiter(current())) {
                addToken(string(1, current()), TokenType::DELIMITER);
                advance();
                continue;
            }
            else {
                addError("Unexpected character: " + string(1, current()));
                advance();
            }
        }

        addToken("", TokenType::ENDOFFILE);
        return {tokens, errors};
    }
};

int main() {
    ifstream file("Project/test.py");
    if (!file) {
        cerr << "Could not open file!" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string input = buffer.str();

    PythonLexer lexer(input);
    auto [tokens, errors] = lexer.tokenize();

    // Print tokens
    for (const auto& token : tokens) {
        cout << "Token: " << token.lexeme << " (" << static_cast<int>(token.type) << ") at " << token.line << ":" << token.column << endl;
    }

    // Print errors
    for (const auto& error : errors) {
        cout << "Error: " << error.message << " at " << error.line << ":" << error.column << endl;
    }

    return 0;
}
