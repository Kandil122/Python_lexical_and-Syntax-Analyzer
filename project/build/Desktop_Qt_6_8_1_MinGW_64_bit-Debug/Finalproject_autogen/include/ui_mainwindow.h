/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QSplitter *mainSplitter;
    QWidget *inputWidget;
    QVBoxLayout *inputLayout;
    QLabel *labelInput;
    QPlainTextEdit *codeInput;
    QHBoxLayout *buttonLayout;
    QPushButton *analyzeButton;
    QPushButton *clearButton;
    QPushButton *openFileButton;
    QSpacerItem *buttonSpacer;
    QWidget *outputWidget;
    QVBoxLayout *outputLayout;
    QTabWidget *analysisTabWidget;
    QWidget *lexicalTab;
    QVBoxLayout *lexicalLayout;
    QSplitter *lexicalSplitter;
    QWidget *tokenWidget;
    QVBoxLayout *tokenLayout;
    QLabel *labelTokens;
    QPlainTextEdit *tokenOutput;
    QWidget *lexicalErrorWidget;
    QVBoxLayout *lexicalErrorLayout;
    QLabel *labelLexicalErrors;
    QPlainTextEdit *lexicalErrorOutput;
    QWidget *symbolTableWidget;
    QVBoxLayout *symbolTableLayout;
    QLabel *labelSymbolTable;
    QTableWidget *symbolTable;
    QWidget *syntaxTab;
    QVBoxLayout *syntaxLayout;
    QSplitter *syntaxSplitter;
    QWidget *syntaxErrorWidget;
    QVBoxLayout *syntaxErrorLayout;
    QLabel *labelSyntaxErrors;
    QPlainTextEdit *syntaxErrorOutput;
    QWidget *parseTreeWidget;
    QVBoxLayout *parseTreeLayout;
    QLabel *labelParseTree;
    QTreeWidget *parseTree;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("/* General window styling */\n"
"QMainWindow {\n"
"    background-color: #2E2E2E;\n"
"}\n"
"\n"
"/* Style for labels */\n"
"QLabel {\n"
"    font: bold 14px \"Arial\";\n"
"    color: #E0E0E0;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Style for text areas */\n"
"QPlainTextEdit {\n"
"    background-color: #1E1E1E;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font: 12px \"Courier New\";\n"
"}\n"
"\n"
"/* Style for table */\n"
"QTableWidget {\n"
"    background-color: #1E1E1E;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 5px;\n"
"    font: 12px \"Courier New\";\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #3E3E3E;\n"
"    color: #E0E0E0;\n"
"    padding: 5px;\n"
"    border: 1px solid #555555;\n"
"}\n"
"\n"
"/* Style for splitter */\n"
"QSplitter::handle {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"QSplitter::handle:hover {\n"
""
                        "    background-color: #666666;\n"
"}\n"
"\n"
"/* Style for buttons */\n"
"QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font: bold 12px \"Arial\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45A049;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3D8B40;\n"
"}\n"
"\n"
"QPushButton#clearButton {\n"
"    background-color: #F44336;\n"
"}\n"
"\n"
"QPushButton#clearButton:hover {\n"
"    background-color: #D32F2F;\n"
"}\n"
"\n"
"QPushButton#clearButton:pressed {\n"
"    background-color: #B71C1C;\n"
"}\n"
"\n"
"QPushButton#openFileButton {\n"
"    background-color: #2196F3;\n"
"}\n"
"\n"
"QPushButton#openFileButton:hover {\n"
"    background-color: #1E88E5;\n"
"}\n"
"\n"
"QPushButton#openFileButton:pressed {\n"
"    background-color: #1976D2;\n"
"}\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(10);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(10, 10, 10, 10);
        mainSplitter = new QSplitter(centralwidget);
        mainSplitter->setObjectName("mainSplitter");
        mainSplitter->setOrientation(Qt::Orientation::Horizontal);
        inputWidget = new QWidget(mainSplitter);
        inputWidget->setObjectName("inputWidget");
        inputLayout = new QVBoxLayout(inputWidget);
        inputLayout->setObjectName("inputLayout");
        inputLayout->setContentsMargins(0, 0, 0, 0);
        labelInput = new QLabel(inputWidget);
        labelInput->setObjectName("labelInput");

        inputLayout->addWidget(labelInput);

        codeInput = new QPlainTextEdit(inputWidget);
        codeInput->setObjectName("codeInput");
        codeInput->setMinimumSize(QSize(0, 200));

        inputLayout->addWidget(codeInput);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        analyzeButton = new QPushButton(inputWidget);
        analyzeButton->setObjectName("analyzeButton");

        buttonLayout->addWidget(analyzeButton);

        clearButton = new QPushButton(inputWidget);
        clearButton->setObjectName("clearButton");

        buttonLayout->addWidget(clearButton);

        openFileButton = new QPushButton(inputWidget);
        openFileButton->setObjectName("openFileButton");

        buttonLayout->addWidget(openFileButton);

        buttonSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(buttonSpacer);


        inputLayout->addLayout(buttonLayout);

        mainSplitter->addWidget(inputWidget);
        outputWidget = new QWidget(mainSplitter);
        outputWidget->setObjectName("outputWidget");
        outputLayout = new QVBoxLayout(outputWidget);
        outputLayout->setObjectName("outputLayout");
        outputLayout->setContentsMargins(0, 0, 0, 0);
        analysisTabWidget = new QTabWidget(outputWidget);
        analysisTabWidget->setObjectName("analysisTabWidget");
        lexicalTab = new QWidget();
        lexicalTab->setObjectName("lexicalTab");
        lexicalLayout = new QVBoxLayout(lexicalTab);
        lexicalLayout->setObjectName("lexicalLayout");
        lexicalSplitter = new QSplitter(lexicalTab);
        lexicalSplitter->setObjectName("lexicalSplitter");
        lexicalSplitter->setOrientation(Qt::Orientation::Vertical);
        tokenWidget = new QWidget(lexicalSplitter);
        tokenWidget->setObjectName("tokenWidget");
        tokenLayout = new QVBoxLayout(tokenWidget);
        tokenLayout->setObjectName("tokenLayout");
        tokenLayout->setContentsMargins(0, 0, 0, 0);
        labelTokens = new QLabel(tokenWidget);
        labelTokens->setObjectName("labelTokens");

        tokenLayout->addWidget(labelTokens);

        tokenOutput = new QPlainTextEdit(tokenWidget);
        tokenOutput->setObjectName("tokenOutput");
        tokenOutput->setMinimumSize(QSize(0, 150));
        tokenOutput->setReadOnly(true);

        tokenLayout->addWidget(tokenOutput);

        lexicalSplitter->addWidget(tokenWidget);
        lexicalErrorWidget = new QWidget(lexicalSplitter);
        lexicalErrorWidget->setObjectName("lexicalErrorWidget");
        lexicalErrorLayout = new QVBoxLayout(lexicalErrorWidget);
        lexicalErrorLayout->setObjectName("lexicalErrorLayout");
        lexicalErrorLayout->setContentsMargins(0, 0, 0, 0);
        labelLexicalErrors = new QLabel(lexicalErrorWidget);
        labelLexicalErrors->setObjectName("labelLexicalErrors");

        lexicalErrorLayout->addWidget(labelLexicalErrors);

        lexicalErrorOutput = new QPlainTextEdit(lexicalErrorWidget);
        lexicalErrorOutput->setObjectName("lexicalErrorOutput");
        lexicalErrorOutput->setMinimumSize(QSize(0, 150));
        lexicalErrorOutput->setReadOnly(true);

        lexicalErrorLayout->addWidget(lexicalErrorOutput);

        lexicalSplitter->addWidget(lexicalErrorWidget);
        symbolTableWidget = new QWidget(lexicalSplitter);
        symbolTableWidget->setObjectName("symbolTableWidget");
        symbolTableLayout = new QVBoxLayout(symbolTableWidget);
        symbolTableLayout->setObjectName("symbolTableLayout");
        symbolTableLayout->setContentsMargins(0, 0, 0, 0);
        labelSymbolTable = new QLabel(symbolTableWidget);
        labelSymbolTable->setObjectName("labelSymbolTable");

        symbolTableLayout->addWidget(labelSymbolTable);

        symbolTable = new QTableWidget(symbolTableWidget);
        if (symbolTable->columnCount() < 4)
            symbolTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        symbolTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        symbolTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        symbolTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        symbolTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        symbolTable->setObjectName("symbolTable");
        symbolTable->setMinimumSize(QSize(0, 150));

        symbolTableLayout->addWidget(symbolTable);

        lexicalSplitter->addWidget(symbolTableWidget);

        lexicalLayout->addWidget(lexicalSplitter);

        analysisTabWidget->addTab(lexicalTab, QString());
        syntaxTab = new QWidget();
        syntaxTab->setObjectName("syntaxTab");
        syntaxLayout = new QVBoxLayout(syntaxTab);
        syntaxLayout->setObjectName("syntaxLayout");
        syntaxSplitter = new QSplitter(syntaxTab);
        syntaxSplitter->setObjectName("syntaxSplitter");
        syntaxSplitter->setOrientation(Qt::Orientation::Vertical);
        syntaxErrorWidget = new QWidget(syntaxSplitter);
        syntaxErrorWidget->setObjectName("syntaxErrorWidget");
        syntaxErrorLayout = new QVBoxLayout(syntaxErrorWidget);
        syntaxErrorLayout->setObjectName("syntaxErrorLayout");
        syntaxErrorLayout->setContentsMargins(0, 0, 0, 0);
        labelSyntaxErrors = new QLabel(syntaxErrorWidget);
        labelSyntaxErrors->setObjectName("labelSyntaxErrors");

        syntaxErrorLayout->addWidget(labelSyntaxErrors);

        syntaxErrorOutput = new QPlainTextEdit(syntaxErrorWidget);
        syntaxErrorOutput->setObjectName("syntaxErrorOutput");
        syntaxErrorOutput->setMinimumSize(QSize(0, 150));
        syntaxErrorOutput->setReadOnly(true);

        syntaxErrorLayout->addWidget(syntaxErrorOutput);

        syntaxSplitter->addWidget(syntaxErrorWidget);
        parseTreeWidget = new QWidget(syntaxSplitter);
        parseTreeWidget->setObjectName("parseTreeWidget");
        parseTreeLayout = new QVBoxLayout(parseTreeWidget);
        parseTreeLayout->setObjectName("parseTreeLayout");
        parseTreeLayout->setContentsMargins(0, 0, 0, 0);
        labelParseTree = new QLabel(parseTreeWidget);
        labelParseTree->setObjectName("labelParseTree");

        parseTreeLayout->addWidget(labelParseTree);

        parseTree = new QTreeWidget(parseTreeWidget);
        parseTree->setObjectName("parseTree");
        parseTree->setMinimumSize(QSize(0, 300));

        parseTreeLayout->addWidget(parseTree);

        syntaxSplitter->addWidget(parseTreeWidget);

        syntaxLayout->addWidget(syntaxSplitter);

        analysisTabWidget->addTab(syntaxTab, QString());

        outputLayout->addWidget(analysisTabWidget);

        mainSplitter->addWidget(outputWidget);

        mainLayout->addWidget(mainSplitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        analysisTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Python Lexer GUI", nullptr));
        labelInput->setText(QCoreApplication::translate("MainWindow", "Enter Python Code:", nullptr));
        codeInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Python code here...", nullptr));
        analyzeButton->setText(QCoreApplication::translate("MainWindow", "Analyze", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        labelTokens->setText(QCoreApplication::translate("MainWindow", "Tokens:", nullptr));
        tokenOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Token output will appear here...", nullptr));
        labelLexicalErrors->setText(QCoreApplication::translate("MainWindow", "Lexical Errors:", nullptr));
        lexicalErrorOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Lexical errors (if any) will appear here...", nullptr));
        labelSymbolTable->setText(QCoreApplication::translate("MainWindow", "Symbol Table:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = symbolTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = symbolTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Identifier", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = symbolTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Data Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = symbolTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        analysisTabWidget->setTabText(analysisTabWidget->indexOf(lexicalTab), QCoreApplication::translate("MainWindow", "Lexical Analysis", nullptr));
        labelSyntaxErrors->setText(QCoreApplication::translate("MainWindow", "Syntax Errors:", nullptr));
        syntaxErrorOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Syntax errors (if any) will appear here...", nullptr));
        labelParseTree->setText(QCoreApplication::translate("MainWindow", "Parse Tree:", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = parseTree->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Node", nullptr));
        analysisTabWidget->setTabText(analysisTabWidget->indexOf(syntaxTab), QCoreApplication::translate("MainWindow", "Syntax Analysis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
