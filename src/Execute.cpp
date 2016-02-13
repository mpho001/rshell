#include <iostream>
#include <queue>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Shell.h"

using namespace std;

void Execute::execute(char** a, bool &comp_status) {
	// create a fork for a child and parent 
	pid_t pid = fork();

	// the child 
	if (pid < 0){
		perror("fork failure");
	}

    if (pid == 0) 
    {
        // then its the child
        if (execvp(a[0], a) == -1) 
	{
            perror("test");
            exit(69);
        }
	else
	{
		exit(0);
	}
    }
    int num = 0;
    wait(&num);
    
    int num_2 = WEXITSTATUS(num);
    
    if(num_2 == 69)
    {
	    comp_status = false;
    }
    if(num_2 == 0)
    {
	    comp_status = true;
    }
   
}
