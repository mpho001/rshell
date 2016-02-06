#include <iostream>
#include <queue>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Shell.h"
#include "Input.h"

using namespace std;

int main() {
    Input in;
    
//    while(1) {

    in.getInput();
    queue<string> tasks = in.Parse();

    char** c;
    while (tasks.size() != 0) {
        c = in.toChar(tasks.front());
        tasks.pop();
    }

    pid_t pid = fork();
    if (pid == 0) {
        // cout << "child: " << pid << endl;
        if (execvp(c[0], c) == -1) {
            perror("exec");
            exit(0);
        }
    }

    if (pid > 0) {
        if ( wait(0) == 1 ) {
            perror("wait");
        }
        // cout << "parent: " << pid << endl;
    }

//    int i = 0;
//    while (c[i] != '\0') {
//        cout << c[i] << endl;
//        ++i;
//    }

    // in.getInput();

    cout << flush;
    delete c;

 //   }

    return 0;

}
