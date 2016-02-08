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
	        void execute(char** a);
};

class Quit: public Shell {
	public:
		// this function would allow us to exit our rshell
		void quit();
};

class Run: public Shell {
	public: 
		//this function we would call to run our rshell
		void run();
};

class Connectors: public Shell {
	protected:
		Shell* conn_type;

	public: 
		// lets us identify the connector to execute the function accord                //  ing to the connector 
		virtual bool behave() = 0;
		virtual void set_behave(Connectors* conn_type);
};
#endif

