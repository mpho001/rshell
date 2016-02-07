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

    char** c = NULL;
    Execute ex;
    while (tasks.size() != 0) {
        if (tasks.front() == "exit") {
            exit(0);
        }
        c = in.toChar(tasks.front());
        ex.execute(c);
        tasks.pop();
    }

//    int i = 0;
//    while (c[i] != '\0') {
//        cout << c[i] << endl;
//        ++i;
//    }

    // in.getInput();

    cout << flush;
    if (c != NULL) {
        delete c;
    }

//    }

    return 0;

}
