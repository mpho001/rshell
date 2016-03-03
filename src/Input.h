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
        char* cmds[50];
        string strLine;
        queue<string> tasks;
    public:
        Input() {};
        bool isTest();
        bool validTest();
        bool chainTest();
        void brackTest();
        void getInput();
        queue<string> Parse();
        queue<string> testParse();
        char** toChar(string a);
};

#endif
