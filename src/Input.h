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
            // null terminated
            cmds[i] = (char*)"\0";
            work.push(cmds);
            i = 0;
            // *cmds = new char[50];
            memset(cmds, 0, sizeof(cmds));
            cmds[i] = p;
            ++i;
            cmds[i] = (char*)"\0";
            work.push(cmds);
            i = 0;
            memset(cmds, 0, sizeof(cmds));
            single = false;
        }

        else {
            // do semicolon check
            // FIX the string
            if (temp.at(temp.size()-1) == ';') {
                //cmds[i] = (char*)";";
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
                cout << "temp: " << temp << endl;
    
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
            else {
                cmds[i] = p;
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
        // cout << *a << ' ';
        work.pop();
    }
}

#endif
