#ifndef __SHELL_H__
#define __SHELL_H__

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <queue>
#include <stack>

using namespace std;

// our main abstract base class, used main for pointers

class Shell {
    public:
        // Constructor and destructor
        Shell() {} ;
        ~Shell() {} ;
        bool isCon(string str) {
            if (str == "&&" || str == "||" || str == ";") {
                return true;
            }
            return false;
        }
};

class Execute: public Shell {
	public:
        Execute(): Shell() {};
		// this function would be used to execute our rshell
	        void execute(char** a, bool &comp_status);
};

class Test: public Shell {
    private:
        struct stat p;
    public:
        Test(): Shell() {};
        bool exists(const char* s);
        bool isReg(const char* s);
        bool isDir(const char* s);
        // is con will see if it's a connector
        // bool isCon(string str);
        void run(queue<string>& q, bool& worked, bool brack);
};

class Connector: public Shell {
    private:
        stack<string> par;
    public:
        Connector(): Shell() {};
        void amp(queue<string>& q, bool status);
        void orr(queue<string>& q, bool status);
        void semi(queue<string>& q);
        void popPar(queue<string>& q);
        void clearStack() {
            while (!par.empty()) {
                par.pop();
            }
        }
};

#endif

