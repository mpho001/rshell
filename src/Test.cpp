#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Shell.h"

using namespace std;

bool Test::exists(const char* s) {
    // p being struct stat
    if (stat(s, &p) == 0) {
        // file exists
        return true;
    }
    return false;
}

bool Test::isReg(const char* s) {
    stat(s, &p);
    if (S_ISREG(p.st_mode)) {
        // file is regular
        return true;
    }
    return false;
}

bool Test::isDir(const char* s) {
    stat(s, &p);
    if (S_ISDIR(p.st_mode)) {
        // it's a directory
        return true;
    }
    return false;
}

bool Test::isCon(string str) {
    if (str == "&&" || str == "||" || str == ";" || str == "("
            || str == ")") {
        return true;
    }
    return false;
}

// if user only inputs test, thats true, because
// we add the -e, in bash thats true...?
// so after we have detected the flag, char s will be
// everything after that until connector or end
void Test::run(queue<string>& q, bool& worked) {
    // if no arguments after flag, then true
    // so, check it end of queue
    // or if a connector been detected
    
    // when ONLY "test" is entered
    if (q.size() == 0 || isCon(q.front())) {
        cout << "(False)" << endl;
        worked = false;
        return;
    }

    if (q.front() == "-e") {  
        q.pop();
        if (q.size() == 0) { 
            cout << "(True)" << endl;
            worked = true; 
            return; 
        }
        if (isCon(q.front())) {
            cout << "(True)" << endl;
            worked = true;
            return;
        }

        // keep checking
        string dir;
        while (q.size() != 0 && !(isCon(q.front()))) {
            dir += q.front();    
            q.pop();
        }
        

        // const char* s = q.front().c_str();
        const char* s = dir.c_str();
        // cout << "directory: " << q.front() << endl;
        if (exists(s)) {
            cout << "(True)" << endl;
            worked = true; 
        }
        else {
            cout << "(False)" << endl;
            worked = false;
        }
        // q.pop();
    }

    else if (q.front() == "-f") {
       q.pop();
       if (q.size() == 0) { return; }
       const char* s = q.front().c_str();
       if (exists(s)) {
           if (isReg(s)) {
               cout << "(True)" << endl;
               worked = true;
           } 
           else {
               cout << "(False)" << endl;
               worked = false;
           }
       }
       else {
           cout << "(False)" << endl;
           worked = false;
       }
       q.pop();
    }

    else if (q.front() == "-d") {
        q.pop();
        if (q.size() == 0) { return; }
        const char* s = q.front().c_str();
        if (exists(s)) {
            if (isDir(s)) {
                cout << "(True)" << endl;
                worked = true;
            }
            else {
                cout << "(False)" << endl;
                worked = false;
            }
        }
        else {
            cout << "(False)" << endl;
            worked = false;
        }
        q.pop();
    }

}