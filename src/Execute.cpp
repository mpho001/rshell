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
	// creates a fork for a child and parent 
	pid_t pid = fork();
	
	// pid is checked to make sure it isn't anything 
	// but a child (pid == 1) or a parent (pid == 1) 
	if (pid < 0) {
		perror("fork not created");
	}
	
	if (pid == 0) {
		// then its the child
		if (execvp(a[0], a) == -1) {
			// if the command fails then we output error
			perror("command not accomplished");
			// we have exit 69 which would store the number
			// 69 for later usage in determining comp_status
			// also any number entered other than 0 to exit
			// makes it return an unsuccessful completition 
			exit(69);
		}
		else{
			// returns a successful completition
			exit(0);
		}
	}
	
	int num = 0;
	//tells the parent to wait
	wait(&num);
	
	// when the exit 69 comes out of the if statement
	// it is scrambled. so wexitstatus unscrambles it
	// and puts it into num_2
	int num_2 = WEXITSTATUS(num);
	
	// if num_2 is 69 then that means it was an 
	// unsuccessful completition and so comp_status 
	// is false
	if(num_2 == 69){
	    comp_status = false;
	}
	
	// if num_2 is 0 then that means it was a 
	// successfuk completition adn so comp_status
	// is true 
	if(num_2 == 0){
		comp_status = true;
	}
}
