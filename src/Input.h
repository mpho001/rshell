#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <queue>
#include <stdlib.h>
#include "Shell.h"

using namespace std;

class Input {
    private:
        string strLine;
        // char* str;
        char* cmds[50];
        vector<string> wholeLine;
        queue<string> tasks;
    public:
        Input() {};
        void getInput();
        queue<string> Parse();
        char** toChar(string a);
};

// if # spotted, cuts off # and everything after it
void Input::getInput() {
    cout << "$ ";
    getline (cin, strLine);
    if (strLine == "exit") {
        cout << "user chose to exit" << endl;
        exit(0);
    }

    if (strLine == "\n") {
        cout << "here" << endl;
    }

    size_t found = strLine.find('#');
    if (found != string::npos) {
        strLine.erase(strLine.begin() + found, strLine.end());
    }
}

queue<string> Input::Parse() {
    istringstream iss(strLine);

    // iss >> ws;
    string token;
    string cmd;
    bool end = true;
    while (getline(iss, token, ' ')) {
        if (token == "&&" || token == "||" || token == ";") {
            tasks.push(cmd);
            cmd.clear();
            tasks.push(token);
            end = false;
        }

        else {
            // check for semicolon
            // remove the extra spaces
            cout << "token: " << token << token.size() << endl;
            if (token.size() != 0 && token.at(token.size() - 1) == ';') {
                token.erase(token.size()-1);
                if (cmd.empty()) {
                    tasks.push(token);
                }
                else {
                    tasks.push(cmd + " " + token);
                    cmd.clear();
                }
                tasks.push(";");
                end = false;
            }

            else {
                if (cmd.empty()) {
                    cmd = token;
                }
                else {
                    cmd = cmd + " " + token;
                }
                end = true;
            }
        }

    }

    if (end) {
        tasks.push(cmd);
    }

    cout << "tasks size: " << tasks.size() << endl;
    // while (tasks.size() != 0) {
    //     cout << tasks.front() << endl;
    //     tasks.pop();
    //}
    return tasks;
}

char** Input::toChar(string a) {
    stringstream stream(a);
    string oneWord;
    int i = 0;
    char** c = new char*[50];
    while (stream >> oneWord) {
        char* ptr = new char[oneWord.size() + 1];
        memcpy(ptr, oneWord.c_str(), oneWord.size() + 1);
        c[i] = ptr;
        ++i;
    }
    return c;
}

#endif
