#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_set>
#include <iomanip>

using namespace std;

unordered_set<string> symbolTable;

bool isPunctuator(char ch) {
    return ispunct(ch) && ch != '_';
}

bool isOperatorChar(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' ||
           ch == '<' || ch == '=' || ch == '&' || ch == '|';
}

bool isCompoundOperator(string s) {
    return s == "++" || s == "--" || s == "==" || s == ">=" || s == "<=" ||
           s == "!=" || s == "&&" || s == "||";
}

bool isKeyword(const string& str) {
    static unordered_set<string> keywords = {
        "if", "else", "while", "do", "break", "continue", "int", "double", "float",
        "return", "char", "case", "long", "short", "typedef", "switch", "unsigned",
        "void", "static", "struct", "sizeof", "volatile", "enum", "const", "union",
        "extern", "bool"
    };
    return keywords.count(str) > 0;
}

bool isNumber(const string& str) {
    int dots = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dots++;
            if (dots > 1) return false;
        }
        else if (!isdigit(str[i])) {
            return false;
        }
    }
    return !str.empty();
}

bool validIdentifier(const string& str) {
    if (str.empty() || isdigit(str[0]) || isPunctuator(str[0]))
        return false;
    for (char ch : str) {
        if (!isalnum(ch) && ch != '_')
            return false;
    }
    return true;
}

void insertToSymbolTable(const string& str) {
    if (validIdentifier(str) && !isKeyword(str)) {
        symbolTable.insert(str);
    }
}

void parse(const string& input) {
    int len = input.length();
    string token = "";
    for (int i = 0; i < len;) {
        // Handle compound operators
        if (isOperatorChar(input[i])) {
            if (i + 1 < len && isOperatorChar(input[i + 1])) {
                string op = string(1, input[i]) + input[i + 1];
                if (isCompoundOperator(op)) {
                    cout << op << " : is an Operator" << endl;
                    i += 2;
                    continue;
                }
            }
            cout << input[i] << " : is an Operator" << endl;
            i++;
        }
        // Punctuation separates tokens
        else if (isPunctuator(input[i])) {
            if (!token.empty()) {
                if (isKeyword(token)) {
                    cout << token << " : is a Keyword" << endl;
                }
                else if (isNumber(token)) {
                    cout << token << " : is a Number" << endl;
                }
                else if (validIdentifier(token)) {
                    cout << token << " : is a valid Identifier" << endl;
                    insertToSymbolTable(token);
                }
                else {
                    cout << token << " : is not a valid Identifier" << endl;
                }
                token.clear();
            }
            i++;
        }
        // Handle space, only break token if next char is punctuator or space is followed by operator/punct
        else if (isspace(input[i])) {
            int j = i + 1;
            while (j < len && isspace(input[j])) j++;
            if (j < len && isPunctuator(input[j])) {
                if (!token.empty()) {
                    if (isKeyword(token)) {
                        cout << token << " : is a Keyword" << endl;
                    }
                    else if (isNumber(token)) {
                        cout << token << " : is a Number" << endl;
                    }
                    else if (validIdentifier(token)) {
                        cout << token << " : is a valid Identifier" << endl;
                        insertToSymbolTable(token);
                    }
                    else {
                        cout << token << " : is not a valid Identifier" << endl;
                    }
                    token.clear();
                }
            }
            else {
                token += ""; // continue collecting spaced token
            }
            i++;
        }
        else {
            token += input[i];
            i++;
        }
    }

    // Handle last token
    if (!token.empty()) {
        if (isKeyword(token)) {
            cout << token << " : is a Keyword" << endl;
        }
        else if (isNumber(token)) {
            cout << token << " : is a Number" << endl;
        }
        else if (validIdentifier(token)) {
            cout << token << " : is a valid Identifier" << endl;
            insertToSymbolTable(token);
        }
        else {
            cout << token << " : is not a valid Identifier" << endl;
        }
    }

    // Print Symbol Table
    cout << "\nSymbol Table:\n";
    int id = 1;
    for (const auto& sym : symbolTable) {
        cout << setw(2) << id++ << "  " << sym << endl;
    }
}

int main() {
    string input;
    cout << "Enter your code: ";
    getline(cin, input);
    parse(input);
    return 0;
}
