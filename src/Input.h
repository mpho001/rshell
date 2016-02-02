#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "Shell.h"

using namespace std;

class Input {
    private:
        string strLine;
        // char* str;
        char* cmds[50];
        vector<string> wholeLine;
        int connType;
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

    char delimit[] = {' ', ';'};

    cout << strLine << endl;
    char str[strLine.size()+1];
    strcpy(str, strLine.c_str());
    char* p = strtok(str, delimit);
    
    // keeps track of location in cmds
    int i = 0;
    while (p != 0) {
        // if (p == "&&" || p == "||" || p == ";")
        cout << p << endl;
        cmds[i] = p;
        ++i;
        p = strtok(NULL, delimit);
    }
    
    // strtok but not making into an array
    // istringstream iss(strLine);
    // string token;
    // while(getline(iss, token, ' ')) {
    //     cout << token << ' ';
    // }
       

}

#endif
