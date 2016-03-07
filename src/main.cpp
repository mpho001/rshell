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
        tasks = in.Parse();

        // bool determines whether command was successful
            bool comp_status = true;
	    bool comp_status2 = true;
	    bool comp_status3 = true;
	    bool comp_status4 = true;
	    bool comp_status5 = true;
	    bool comp_status6 = true;
	    bool comp_status7 = true;
	    bool comp_status8 = true;
	    bool comp_status9 = true;
	    bool comp_status10 = true;
	    int hash = -1;
	    Connector con;
            char** c;
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
		        hash = 0;
			con.amp(tasks, comp_status);
            }

            //------------------------------------------------------------------


            else if (tasks.front() == "||") {
			    hash = 0;
			    con.orr(tasks, comp_status);
	        }
            
            // simply pop the semicolon and continue looping
	        else if (tasks.front() == ";") {
		        tasks.pop();

	        }

	    //------------------------------------------------------------------
	    
	    else if (tasks.front() == "(") {
		    if (hash == 1) {
			    perror("no connector before (");
			    break;
		    }

		    bool bal;
		    
		    con.balance(tasks, bal);
		    if (bal == false) {
			    perror("parentheses not balanced");
			    break;
		    }
		    
		    tasks.pop();
		    int num = 1;
		    while (num != 0) {
			    if (tasks.front() == "&&") {
				   // if num equals one meaning
				   // if we are inside one paren the single
				   // commands are bool stat 2
				   if (num == 1) {
					   con.amp(tasks, comp_status2);
				   }

				   // if num equals two meaning
				   // if we are inside 2 paren the single
				   // commands are bool stat 3
				   else if (num == 2) {
					   con.amp(tasks, comp_status3);
				   }

				   else if (num == 3) {
					   con.amp(tasks, comp_status4);
				   }

				   else if (num == 4) {
					   con.amp(tasks, comp_status5);
				   }

				   else if (num == 5) {
					   con.amp(tasks, comp_status6);
				   }

				   else if (num == 6) {
					   con.amp(tasks, comp_status7);
				   }

				   else if (num == 7) {
					   con.amp(tasks, comp_status8);
				   }

				   else if (num == 8) {
					   con.amp(tasks, comp_status9);
				   }

				   else if (num == 9) {
					   con.amp(tasks, comp_status10);
				   }
			    }

			    else if (tasks.front() == "||") {
				    // if num is 1 then comp 2
				    // gets sent to orr
				    // cause thats just a single
				    // parentheses
				    if (num == 1) {
					    con.orr(tasks, comp_status2);
				    }

				    // if num is 2 then comp 3
				    // gets sent to orr
				    // cause thats just a double
				    // parentheses
				    else if (num == 2) {
					    con.orr(tasks, comp_status3);
				    }

				    else if (num == 3) {
					    con.orr(tasks, comp_status4);
				    }

				    else if (num == 4) {
					    con.orr(tasks, comp_status5);
				    }

				    else if (num == 5) {
					    con.orr(tasks, comp_status6);
				    }

				    else if (num == 6) {
					    con.orr(tasks, comp_status7);
				    }

				    else if (num == 7) {
					    con.orr(tasks, comp_status8);
				    }

				    else if (num == 8) {
					    con.orr(tasks, comp_status9);
				    }

				    else if (num == 9) {
					    con.orr(tasks, comp_status10);
				    }
			    }

			    else if (tasks.front() == ";") {
				   con.semi(tasks);
			    }
			    
			    else if (tasks.front() == "(") {
				    tasks.pop();
				    num++;
			    }

			    else if (tasks.front() == ")") {
				    tasks.pop();

				    // if num equals 9 then
				    // we know comp stat 10
				    // is used for comp stat 9
				    // meaning that 9 paren in 
				    // 8 paren so comp 10's status
				    // determines comp 9's status
				    if (num == 9) {
					    if (comp_status10 == false) {
						    comp_status9 = false;
					    }
					    else {
						    comp_status9 = true;
					    }
				    }
				    else if (num == 8) {
					    if (comp_status9 == false) {
						    comp_status8 = false;
					    }
					    else {
						    comp_status8 = true;
					    }
				    }
				    else if (num == 7) {
					    if (comp_status8 == false) {
						    comp_status7 = false;
					    }
					    else {
						    comp_status7 = true;
					    }
				    }
				    else if (num == 6) {
					    if (comp_status7 == false) {
						    comp_status6 = false;
					    }
					    else {
						    comp_status6 = true;
					    }
				    }
				    else if (num == 5) {
					    if (comp_status6 == false) {
						    comp_status5 = false;
					    }
					    else {
						    comp_status5 = true;
					    }
				    }
				    else if (num == 4) {
					    if (comp_status5 == false) {
						    comp_status4 = false;
					    }
					    else {
						    comp_status4 = true;
					    }
				    }
				    else if (num == 3) {
					    if (comp_status4 == false) {
						    comp_status3 = false;
					    }
					    else {
						    comp_status3 = true;
					    }
				    }
				    else if (num == 2) {
					    if (comp_status3 == false) {
						    comp_status2 = false;
					    }
					    else {
						    comp_status2 = true;
					    }
				    }
				    num = num - 1; 
			    }
			    
			    else {
				    if (num == 9) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status10, brack); 
					    }
					    
					    else { 
						    c = in.toChar(tasks.front());
						    ex.execute(c, comp_status10);
						    tasks.pop();
					    }
				    }
				    
				    else if (num == 8) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status9, brack);
					    }
					    else {
						    c = in.toChar(tasks.front());
						    ex.execute(c, comp_status9);
						    tasks.pop();
					    } 
				    }
				    
				    else if (num == 7) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status8, brack); 
					    }
					    else {
						    c = in.toChar(tasks.front());
						    ex.execute(c, comp_status8);
						    tasks.pop();
					    } 
				    }
				    
				    else if (num == 6) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status7, brack); 
					    }
					    else {
						    c = in.toChar(tasks.front());
					            ex.execute(c, comp_status7);
					            tasks.pop();
					    } 
				    }
				    
				    else if (num == 5) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status6, brack); 
					    }
					    else {
						    c = in.toChar(tasks.front());
					            ex.execute(c, comp_status6);
					            tasks.pop();
					    }
				    }
				    
				    else if (num == 4) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status5, brack); 
					    }
					    else {
						    c = in.toChar(tasks.front());
					            ex.execute(c, comp_status5);
					            tasks.pop();
					    }
				    }
				    
				    else if (num == 3) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status4, brack); 
					    }
					    else {
						    c = in.toChar(tasks.front());
					            ex.execute(c, comp_status4);
					            tasks.pop();
					    }
				    }
				    
				    else if (num == 2) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status3, brack); 
					    }
					    else {
						    c = in.toChar(tasks.front());
					            ex.execute(c, comp_status3);
					            tasks.pop();
					    }
				    }

				    else if (num == 1) {
					    if (tasks.front() == "test" || tasks.front() == "[") {
						    bool brack = false;
						    if (tasks.front() == "[") {
							    brack = true;
						    }
						    tasks.pop();
						    test.run(tasks, comp_status2, brack); 
					    }
					    else {
						    c = in.toChar(tasks.front());
						    ex.execute(c, comp_status2);
						    tasks.pop();
					    }
				    }
			    }
		    }

		    if (comp_status2 == false) {
			    comp_status = false;
		    }

		    else {
			    comp_status = true;
		    }
	    }


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
	            hash = 1;
	    	    tasks.pop();
	        }
	}
	cout << flush;
    }
    return 0;
}
