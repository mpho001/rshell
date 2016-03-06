#include <iostream>
#include "Input.h"
#include <queue>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <algorithm>

using namespace std;

// void Input::setUser() {
// }

void Input::getInput() {
    strLine.clear();
    cout << "$ ";
    getline (cin, strLine);
    
    // if the user ONLY entered exit  
    if (strLine == "exit") {
        cout << "You have exited shell." << endl;
        exit(0);
    }

    // if # spotted, cuts off # and everything after it
    size_t found = strLine.find('#');
    if (found != string::npos) {
        strLine.erase(strLine.begin() + found, strLine.end());
        if (strLine.size() == 0) {
            // cout << "nothing left" << endl;
        }
    }
}

bool Input::isTest() {
    size_t found = strLine.find('[');
    if (found != string::npos) {
        if ( validTest() ) {
            return true;
        }
        return false;
    }
    
    // check if test is first word in string or after connector
    if (strLine.find("test ") != string::npos) {
        return true;
    }

    return false;
}

// handle error when user puts something like "] [" wtf
bool Input::validTest() {
    size_t cntrOpen  = std::count(strLine.begin(), strLine.end(), '[');
    size_t cntrClose = std::count(strLine.begin(), strLine.end(), ']');

    if (cntrOpen == cntrClose) {
        return true;
    }
    return false;
}

void Input::brackTest() {
    // handles [ ]
}

// if semicolon, erase 
void Input::semicolon(queue<string>& q, string s) {
    if (s.size() != 0 && s.at(s.size()-1) == ';') {
        s.erase(s.size()-1);
        q.push(s);
        q.push(";");
    }
    else {
        q.push(s);
    }
}


// returns a queue of parsed string
queue<string> Input::Parse() {
    // checks if there's anything
    // cout << "test: " << strLine << endl;
    
    // clears tasks queue
    queue<string> empty;
    swap(tasks, empty);

    if (strLine.size() == 0) {
        return tasks;
    }
    
    // checks if string has only spaces
    if (strLine.find_first_not_of(' ') == string::npos) {
        return tasks;
    }

    istringstream iss(strLine);

    // iss >> ws;
    string token;
    string cmd;
    // end used to determine if its end of user input
    bool end = true;
    bool start = true;
    // if a connector was just detected
    bool con = false;
    // if there is a parentheses
    bool paren = false;
    bool tested = false;

    // ignores ' '
    while (getline(iss, token, ' ')) {
         if ( (start && token == "test") || (con && token == "test" )) {
            tasks.push(token);
            if (getline(iss, token, ' ')) {
                if (token == "-e" || token == "-f" || token == "-d") {
                    tasks.push(token);
                    if (getline(iss, token, ' ')) {
                        // tasks.push(token);
                        semicolon(tasks, token);
                    }
                    // strLine empty
                    else {return tasks;}
                }
                else if (token != "&&" && token != "||" && token != ";") {
                    tasks.push("-e");
                    // tasks.push(token);
                    semicolon(tasks, token);
                }
                else if (token == "&&" || token == "||" || token == ";") {
                    // tasks.push(token);
                    semicolon(tasks, token);
                }
            }
            end = false;
            tested = true;
        }        

        // removed else if
         else if (token == "&&" || token == "||" || token == ";"  || 
                 token == "(" || token == ")") {
            // pushes whatever cmd was
            // if (!tested) {
            if (!cmd.empty()) {
                tasks.push(cmd);
            }
            // makes string empty
            cmd.clear();
            // pushes &&, ||, or ;
            tasks.push(token);
            if (token == "(") {paren = true;}
            end = false;
            con = true;
            tested = false;
        }
        
        // if you see [, keep reading til you see ]
        else if ( (start && token == "[") || (con && token == "[") ) {
            tasks.push(token);
            while (token != "]") {
                if (getline(iss, token, ' ')) {
                    // tasks.push(token);
                    semicolon(tasks, token);
                }
                // empty
                else {return tasks;}
            }
            end = false;
            con = false;
            tested = false;
        }


        
	    // would see if the first char of token is 
	    // ( then would push ( delete it from
	    // the token then push the actual token in
	    // would set paren to true letting 
	    // it know that there is a closing
	    // paren to look for

	    else if (token.at(0) == '(') {
            while (token.at(0) == '(') {
	            paren = true;
    	        tasks.push("(");
	            token.erase(0, 1);
	            // tasks.push(token);
                if (cmd.empty() && !token.empty() && token.at(0) != '(') {
                    cmd = token;
                }
                else if (!cmd.empty()) {
                    cmd += " " + token;
                }
            }
            end = false;
            con = false;
	    }

	    // would check to see if paren is true 
	    // and would see is the last char in
	    // token is ) then would erase ) from token
	    // push the token in push the 
	    // ) in and make paren false again
	    // so that it know the braket is closed 
	    else if (paren == true && token.at(token.size() - 1) == ')') {
            int count = 0;
            while (token.at(token.size() - 1) == ')') {
                token.erase(token.size()-1);
                ++count;
                if (cmd.empty() && !token.empty() && token.at(0) != ')') {
                    // cout << "1: " << token << endl;
                    // tasks.push(token);
                    cmd = token;
                }
                else if (!cmd.empty() && token.at(token.size()-1) != ')') {
                    // tasks.push(cmd + " " + token);
                    // cmd.clear();
                    cmd += " " + token;
                }
	            // tasks.push(token);
	            // tasks.push(")");
            }
            tasks.push(cmd);
            cmd.clear();
	        // paren = false;
            while (count != 0) {
                tasks.push(")");
                count -= 1;
            }
            end = false;
            con = false;
	    }	
        // else if not a connector
       
        // else if (strLine.find("&&") != std::string::npos) {
        //     cout << "found &&" << endl;
            // find position and split up string accordingly
        // }

        else { //if (!tested) {
            // check if end of token has semicolon
            // remove the extra spaces
            // cout << "token: " << token << token.size() << endl;
            if (token.size() != 0 && token.at(token.size() - 1) == ';') {
                token.erase(token.size()-1);
                if (cmd.empty()) {
                    tasks.push(token);
                }
                else {
                    tasks.push(cmd + " " + token);
                    cmd.clear();
                }
                tasks.push(";");
                end = false;
            }

            
            // check if connectors are hidden in words
            
            // no semicolon detected at end of word
            else {
                if (cmd.empty()) {
                    cmd = token;
                }
                else {
                    cmd = cmd + " " + token;
                }
                end = true;
            }
            con = false;
            tested = false;
        }

        start = false;
    }
    
    // if no more connectors were detected
    if (end) {
        tasks.push(cmd);
    }

    // check if last thing in task is a && or ||
    // if (token == "&&" || token == "||") {
        // get user input again
    //     getInput();
    //     Parse();
    // }

    return tasks;
}

// converts a token to char**
char** Input::toChar(string a) {
    stringstream stream(a);
    string oneWord;
    int i = 0;
    char** c = new char*[1024];
    // one word at a time
    while (stream >> oneWord) {
        // allocating memory
        char* ptr = new char[oneWord.size() + 1];
        // copies string (converted to c-string) to ptr)
        memcpy(ptr, oneWord.c_str(), oneWord.size() + 1);
        c[i] = ptr;
        ++i;
    }
    
    // null terminates the char**
    c[i] = '\0';

    return c;
}


