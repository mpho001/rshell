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

void Test::run(queue<string>& q) {
    // if no arguments after flag, then true
    // so, check it end of queue
    // or if a connector been detected

    if (q.size() == 0) { return; }
    if (q.front() == "-e") {  
        q.pop();
        if (q.size() == 0) { return; }
        const char* s = q.front().c_str();
        cout << "directory: " << q.front() << endl;
        if (exists(s)) {
            cout << "(True)" << endl;
        }
        else {
            cout << "(False)" << endl;
        }
        q.pop();
    }

    else if (q.front() == "-f") {
       q.pop();
       if (q.size() == 0) { return; }
       const char* s = q.front().c_str();
       if (exists(s)) {
           if (isReg(s)) {
               cout << "(True)" << endl;
           } 
           else {
               cout << "(False)" << endl;
           }
       }
       else {
           cout << "(False)" << endl;
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
            }
            else {
                cout << "(False)" << endl;
            }
        }
        else {
            cout << "(False)" << endl;
        }
        q.pop();
    }
}
           


