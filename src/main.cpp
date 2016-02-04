#include <iostream>
#include <queue>
#include "Shell.h"
#include "Input.h"

using namespace std;

int main() {
    Input in;

    in.getInput();
    queue<string> tasks = in.Parse();

    char** c;
    while (tasks.size() != 0) {
        c = in.toChar(tasks.front());
        tasks.pop();
    }

    int i = 0;
    while (c[i] != '\0') {
        cout << c[i] << endl;
        ++i;
    }

    delete c;

    return 0;

}
