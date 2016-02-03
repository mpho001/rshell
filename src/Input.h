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
        char* connType[50];
        vector<string> wholeLine;
        queue<char** > work;
    public:
        Input() {};
        void getInput();
        void parse();
};

void Input::getInput() {
    getline (cin, strLine);
}

// make string into array
// breaks up line and stores tokens
void Input::parse() {

    char delimit[] = {' '};

    cout << strLine << endl;
    char str[strLine.size()+1];
    strcpy(str, strLine.c_str());
    char* p = strtok(str, delimit);
    
    // keeps track of location in arrays
    int i = 0;
    bool single = true;
    while (p != 0) {
        string temp = p;
        if (temp == "&&" || temp == "||" || temp == ";") {
            work.push(cmds);
            i = 0;
            *cmds = new char[50];
            cmds[i] = p;
            ++i;
            work.push(cmds);
            i = 0;
            *cmds = new char[50];
            single = false;
        }

        // cout << p << endl;
        else {
            // do semicolon check
            // FIX the string
            if (temp.at(temp.size()-1) == ';') {
                cmds[i] = (char*)";";
                work.push(cmds);
                *cmds = new char[50];
                i = 0;
                temp.erase(temp.size()-1);
                cout << "temp: " << temp << endl;
                char test[temp.size()+1];
                strcpy(test, temp.c_str());
                cmds[i] = test;
                ++i;
            }
            else {
                cmds[i] = p;
                ++i;
            }
            single = true;
        }

        p = strtok(NULL, delimit);
    }

    if (single) {
        work.push(cmds);
    }

    cout << "work size: " << work.size() << endl;
       
    while (work.size() != 0) {
        char** a = work.front();
        cout << *a << ' ';
        work.pop();
        cout << "up: " << work.size() << endl;
    }

}

#endif
