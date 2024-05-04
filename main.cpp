#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// List of C++ keywords for reference
vector<string> keywords = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

bool isKeyword(const string &word) {
    return find(keywords.begin(), keywords.end(), word) != keywords.end();
}

bool isPunctuation(char ch) {
    return ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}';
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>'||ch =='%';
}

int main() {
    ifstream file("lex_input.txt.txt");
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    char ch;
    string buffer;
    while (file >> noskipws >> ch) {
        if (isPunctuation(ch) || isOperator(ch) || ch == ' ' || ch == '\n') {
            if (!buffer.empty()) {
                if (isKeyword(buffer)) {
                    cout << buffer << " is a keyword\n";
                }
                else{
                    cout << buffer << " is an identifier\n";
                }
                buffer.clear();
            }
            if (isPunctuation(ch)) {
                cout << ch << " is a punctuation\n";
            } else if (isOperator(ch)) {
                cout << ch << " is an operator\n";
            }
        } else {
            buffer += ch;
        }
    }

    file.close();
    return 0;
}
