#include <iostream>
#include <queue>
#include "Shell.h"
#include "Input.h"

using namespace std;

int main() {
    Input in;

    in.getInput();
   // in.parse(); cout << endl;
    in.Parse();

    queue<char** > test;
    char* a[3];
    a[0] = (char*)"hello there";
    a[1] = (char*)"omg";
    a[2] = (char*)"\0";

    char* b[3];
    b[0] = (char*)"poo";
    b[1] = (char*)"uh";
    b[2] = (char*)"\0";

    test.push(a);
    test.push(b);
    int i = 0;
    while (test.size() != 0) {
        char** c = test.front();
        i = 0;
        while (c[i] != "\0") {
//            cout << c[i] << ' ';
            ++i;
        }
        test.pop();
    }
//    cout << endl;


    return 0;

}
