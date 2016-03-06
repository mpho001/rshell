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
    queue<string> tasks;
    
    // to exit while loop, user must type exit 
    while(1) {

        in.getInput();
        // bool test = in.isTest();
        // cout << "test: " << test << endl;
        // exit(0);
        tasks = in.Parse();

         cout << "size: " << tasks.size() << endl;

         while (tasks.size() != 0) {
             cout << tasks.front() << endl;
             tasks.pop();
         }

         exit(0);
        
        // bool determines whether command was successful
        bool comp_status = true;
	bool comp_status2 = false;
	bool check = false;
        char** c;
	    // int num = 0;
        Execute ex;

        // TEST STUFF
        Test test;


        while (tasks.size() != 0) {
        
            // if at any point the user has exit
            if (tasks.front() == "exit") {
                cout << "You have exited shell." << endl;
                exit(0);
            }

            //------------------------------------------------------------------

            else if (tasks.front() == "&&") {
	            tasks.pop(); //gets rid of the &&
                // if the command before this one does returns F,then dont do
                // //the next command
	            if(comp_status == false) {
		        // so the && connector should have already been deleted,
                // this is a while loop to
                // delete the next commands so that they wont run if
                // the command before fails  
		            if(tasks.size() != 0) {
                        if (tasks.front() == "test") {
                            // delete all of test
                            while (tasks.size() != 0 && tasks.front() != "&&" &&
                                tasks.front() != "||" && tasks.front() != ";") {
                                tasks.pop();
                            }
                        } 
                        else if(tasks.front() != "&&" || tasks.front() != "||" 
                                || tasks.front() != ";") {
				            tasks.pop();
			            }
		            }
	            }
            }
            //------------------------------------------------------------------


            else if (tasks.front() == "||") {
		        tasks.pop();  // gets rid of the || 
		        if(comp_status == true) {
			        if(tasks.size() != 0) {
					if (tasks.front() == "test") {
					       	// delete all of test 
						   while (tasks.size() != 0 && tasks.front() != "&&" && tasks.front() != "||" && tasks.front() != ";") { 
							   tasks.pop();
						   }
					}
					else if (tasks.front() != "&&" || tasks.front() != "||" || tasks.front() != ";") {
				 	        tasks.pop();
			  	        }
		  	        }   
		        }
	        }
            
            // simply pop the semicolon and continue looping
	    else if (tasks.front() == ";") {
		    tasks.pop();
	    }

	    //------------------------------------------------------------------
	    
	    else if (tasks.front() == "(") {
		    // gets rid of (
		    tasks.pop();
		    while (task.front() != ")" && check == false) {
			    if (tasks.front() == "&&") {
				    amp(task.front(),
		    



            //-----------------------------------------------------------------
            
            
            // the user wants to test
            else if (tasks.front() == "test" || tasks.front() == "[") {
                // pops "test"
                bool brack = false;
                if (tasks.front() == "[") {
                    brack = true;
                }
                tasks.pop();
                test.run(tasks, comp_status, brack);
            }

            // task was not a connector, and therefore a command 
            else { 
                c = in.toChar(tasks.front());
                ex.execute(c, comp_status);
	            tasks.pop();
	        }
            
        }
    cout << flush;

    }

    return 0;
}
