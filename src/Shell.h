#ifndef __SHELL_H__
#define __SHELL_H__

#include <iostream>

using namespace std;

class Shell {
    public:
        // Constructor and destructor
        Shell();
        ~Shell();
        virtual void run() = 0;
};


#endif

