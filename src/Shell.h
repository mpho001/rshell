#ifndef __SHELL_H__
#define __SHELL_H__

#include <iostream>

using namespace std;

// our main abstract base class, used main for pointers

class Shell {
    public:
        // Constructor and destructor
        Shell();
        ~Shell();
};

class Execute: public Shell {
	public:
		// this function would be used to execute our rshell
	        void execute();
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
	public: 
		// this we would lead into our connectors and try to identify th                //  m
		virtual bool behave() = 0;
};

class And: public Connectors {
	public:
		// this would identify if the connector is and
		bool behave();
};

class Semi: public Connectors {
	public:
		// this would identify if the connector is semi 	
		bool behave();
};

class Or: public Connectors {
	public:
		// this would identify if the connector is or
		bool behave();
};
#endif

