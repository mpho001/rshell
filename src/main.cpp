#include <iostream>
#include "Shell.h"
#include "Input.h"

using namespace std;

int main() {

    cout << "hello world" << endl;

    Input in;

    in.getInput();
    in.parse(); cout << endl;



    return 0;

}
