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

#endif
