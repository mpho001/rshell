#include <iostream>
#include <queue>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Shell.h"

using namespace std;

bool Execute::execute(char** a) {
    pid_t pid = fork();
    if (pid == 0) {
        // then its the child
        if (execvp(a[0], a) == -1) {
            // then it failed
            perror("didn't work");
            // will return a false to let possible connector know that the task 	    //was not fullfilled
            return false;
        }
    }

    else {
        // this is the parent
        // we want to wait for the child to finish
        if (wait(0) == 1) {
            perror("wait");
        }
    }

    return true;
}
