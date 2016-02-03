#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <queue>
#include "Shell.h"

using namespace std;

class Input {
    private:
        string strLine;
        // char* str;
        char* cmds[50];
        vector<string> wholeLine;
        queue<char** > work;
        queue<string> tasks;
    public:
        Input() {};
        void getInput();
        void parse();
        void Parse();
};

void Input::getInput() {
    getline (cin, strLine);
}

// make string into array
// breaks up line and stores tokens
void Input::parse() {

    char delimit[] = {' '};

    char str[strLine.size()+1];
    strcpy(str, strLine.c_str());
    char* p = strtok(str, delimit);
    
    // keeps track of location in arrays
    int i = 0;
    // is it last part of line
    bool single = true;
    while (p != 0) {
        string temp = p;
        if (temp == "&&" || temp == "||" || temp == ";") {
            // null terminated
            //cmds[i] = (char*)"\0";
            //work.push(cmds);
            //i = 0;
            //memset(cmds, 0, sizeof(cmds));
            //cmds[i] = p;
            //++i;
            //cmds[i] = (char*)"\0";
            //work.push(cmds);
            //i = 0;
            //memset(cmds, 0, sizeof(cmds));
            single = false;
        }

        else {
            // do semicolon check
            // FIX when semicolon at the end
            // it gives segfault
            if (temp.at(temp.size()-1) == ';') {
                //if (i != 0) {
                //    work.push(cmds);
                //    memset(cmds, 0, sizeof(cmds));
                //    i = 0;
                //}

                //cmds[i] = (char*)";";
                //work.push(cmds);
                //memset(cmds, 0, sizeof(cmds));
                //i = 0;

                temp.erase(temp.size()-1);
    
                char arr[1024];
                strncpy(arr, temp.c_str(), sizeof(arr));
                arr[sizeof(arr) - 1] = 0;
                cmds[i] = arr;
                ++i;
                cmds[i] = (char*)"\0";
                work.push(cmds);
                memset(cmds, 0, sizeof(cmds));
                i = 0;

                cmds[i] = (char*)";";
                ++i;
                cmds[i] = (char*)"\0";
                work.push(cmds);
                memset(cmds, 0, sizeof(cmds));
                i = 0;
                single = false;
            }
            // no semicolon at the end
            else {
                cmds[i] = p;
                cout << "just word: ";
                cout << cmds[i] << endl;
                ++i;
                single = true;
            }
            //single = true;
        }

        p = strtok(NULL, delimit);
    }

    if (single) {
        cmds[i] = (char*)"\0";
        work.push(cmds);
    }

    cout << "work size: " << work.size() << endl;
       
    while (work.size() != 0) {
         char** a = work.front();
         int k = 0;
         while (a[k] != "\0") {
             cout << a[k] << ' ';
             ++k;
         }
        work.pop();
    }
}

void Input::Parse() {
    istringstream iss(strLine);
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
            if (token.at(token.size() - 1) == ';') {
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
    while (tasks.size() != 0) {
        cout << tasks.front() << endl;
        tasks.pop();
    }

}

#endif
