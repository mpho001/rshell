#include <iostream>
#include <queue>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Shell.h"

using namespace std;

void Execute::execute(char** a, bool &comp_status) 
{
    comp_status = true;	
    cout << "first " << comp_status << endl;
    pid_t pid = fork();
    if (pid == 0) 
    {
        // then its the child
        if (execvp(a[0], a) == -1) 
	{
	    comp_status = false;
	    //comp_status = false;
            cout << comp_status << endl;
	    // then it failed
            perror("test");
            // will return a false to let possible connector know that the task 	    //was not fullfilled
	    exit(EXIT_FAILURE);
        }
    }

    else {
        // this is the parent
	// we want to wait for the child to finish
	if (wait(0) == 1) {
            perror("wait");
        }
	cout << "in parent" << endl;
    }
    cout << "after everything " << comp_status << endl;

}
