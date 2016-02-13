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
    
    while(1) {

        in.getInput();
        tasks = in.Parse();

        bool comp_status = true;
        char** c;
        Execute ex;
        //bool worked = true;
        while (tasks.size() != 0) {
        
            // if at any point the user has exit
            if (tasks.front() == "exit") {
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
			            if(tasks.front() != "&&" || tasks.front() != "||" ||
                                tasks.front() != ";") {
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
			  	        if (tasks.front() != "&&" || tasks.front() != "||" ||
                                tasks.front() != ";") {
				 	        tasks.pop();
			  	        }
		  	        }   
		        }
	        }

	        else if (tasks.front() == ";") {
                tasks.pop();
	        }


    //--------------------------------------------------------------------------

        
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
