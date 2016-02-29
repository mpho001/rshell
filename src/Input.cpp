#include <iostream>
#include "Input.h"
#include <queue>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>

using namespace std;

// void Input::setUser() {
// }

void Input::getInput() {
    strLine.clear();
    cout << "$ ";
    getline (cin, strLine);
    
    // if the user ONLY entered exit  
    if (strLine == "exit") {
        cout << "You have exited shell." << endl;
        exit(0);
    }

    // if # spotted, cuts off # and everything after it
    size_t found = strLine.find('#');
    if (found != string::npos) {
        strLine.erase(strLine.begin() + found, strLine.end());
        if (strLine.size() == 0) {
            // cout << "nothing left" << endl;
        }
    }
}

// returns a queue of parsed string
queue<string> Input::Parse() {
    // checks if there's anything
    // cout << "test: " << strLine << endl;
    
    // clears tasks queue
    queue<string> empty;
    swap(tasks, empty);

    if (strLine.size() == 0) {
        return tasks;
    }
    
    // checks if string has only spaces
    if (strLine.find_first_not_of(' ') == string::npos) {
        return tasks;
    }

    istringstream iss(strLine);

    // iss >> ws;
    string token;
    string cmd;
    // end used to determine if its end of user input
    bool end = true;
    // ignores ' '
    while (getline(iss, token, ' ')) {
        if (token == "&&" || token == "||" || token == ";") {
            // pushes whatever cmd was
            tasks.push(cmd);
            // makes string empty
            cmd.clear();
            // pushes &&, ||, or ;
            tasks.push(token);
            end = false;
        }
        
        // else if not a connector
       
        // else if (strLine.find("&&") != std::string::npos) {
        //     cout << "found &&" << endl;
            // find position and split up string accordingly
        // }

        else {
            // check if end of token has semicolon
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
            
            // check if connectors are hidden in words
            
            // no semicolon detected at end of word
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

    // check if last thing in task is a && or ||
    // if (token == "&&" || token == "||") {
        // get user input again
    //     getInput();
    //     Parse();
    // }

    return tasks;
}

// converts a token to char**
char** Input::toChar(string a) {
    stringstream stream(a);
    string oneWord;
    int i = 0;
    char** c = new char*[1024];
    // one word at a time
    while (stream >> oneWord) {
        // allocating memory
        char* ptr = new char[oneWord.size() + 1];
        // copies string (converted to c-string) to ptr)
        memcpy(ptr, oneWord.c_str(), oneWord.size() + 1);
        c[i] = ptr;
        ++i;
    }
    
    // null terminates the char**
    c[i] = '\0';

    return c;
}


