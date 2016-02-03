#include <iostream>
#include <queue>
#include "Shell.h"
#include "Input.h"

using namespace std;

int main() {
    Input in;

    in.getInput();
    in.parse(); cout << endl;

    queue<char** > test;
    char* a[3];
    a[0] = (char*)"hello there";
    a[1] = (char*)"omg";
    a[2] = (char*)"\0";

    test.push(a);
    int i = 0;
    while (test.size() != 0) {
        char** b = test.front();
        while (b[i] != "\0") {
//            cout << b[i] << ' ';
            ++i;
        }
        test.pop();
    }
//    cout << endl;


    return 0;

}
