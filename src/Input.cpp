#include <iostream>
#include "Input.h"
#include <queue>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

// if # spotted, cuts off # and everything after it
void Input::getInput() {
    cout << "$ ";
    getline (cin, strLine);
     //if (strLine == "exit") {
     //    cout << "user chose to exit" << endl << flush;
     //    exit(0);
     //}

    // if (strLine == "\n") {
    //    cout << "here" << endl;
    // }

    size_t found = strLine.find('#');
    if (found != string::npos) {
        strLine.erase(strLine.begin() + found, strLine.end());
    }
}

// returns a queue of parsed string
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
            // cout << "token: " << token << token.size() << endl;
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
    
    // if no more connectors were detected
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

// converts a token to char**
char** Input::toChar(string a) {
    stringstream stream(a);
    string oneWord;
    int i = 0;
    char** c = new char*[50];
    // one word at a time
    while (stream >> oneWord) {
        char* ptr = new char[oneWord.size() + 1];
        // copies string (converted to c-string) to ptr)
        memcpy(ptr, oneWord.c_str(), oneWord.size() + 1);
        c[i] = ptr;
        ++i;
    }
    return c;
}


