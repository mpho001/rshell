#ifndef __SHELL_H__
#define __SHELL_H__

#include <iostream>

using namespace std;

// our main abstract base class, used main for pointers

class Shell {
    public:
        // Constructor and destructor
        Shell() {} ;
        ~Shell() {} ;
};

class Execute: public Shell {
	public:
        Execute(): Shell() {};
		// this function would be used to execute our rshell
	        void execute(char** a, bool &comp_status);
};

#endif

