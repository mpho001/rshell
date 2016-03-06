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

        // while (tasks.size() != 0) {
        //     cout << tasks.front() << endl;
        //     tasks.pop();
        // }

        // exit(0);
        
        // bool determines whether command was successful
        bool comp_status = true;
	    bool comp_status2 = false;
	    bool comp_status3 = false;
	    bool comp_status4 = false;
	    bool comp_status5 = false;
	    bool comp_status6 = false;
	    bool comp_status7 = false;
	    bool comp_status8 = false;
	    bool comp_status9 = false;
	    bool comp_status10 = false;
	    int hash = -1;
        //	bool check = false;
	    Connector con;
        char** c;
	    // int num = 0;
        Execute ex;

        // TEST STUFF
        Test test;


        while (tasks.size() != 0) {
//		cout << tasks.front() << " check" << endl;
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
		    hash = 0;
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
				if (tasks.front() == "(") {
					int count = 1;
					tasks.pop();
					while (count != 0) {
						if (tasks.front() == "(") {
							count++;
						}
						else if (tasks.front() == ")") {
							count = count - 1;
						}
						tasks.pop();
					}
				}
			}
		}
	}
}

            //------------------------------------------------------------------


            else if (tasks.front() == "||") {
		        tasks.pop();  // gets rid of the || 
		       // cout << tasks.front() << endl;
			    hash = 0;
			    if(comp_status == true) {
			        if(tasks.size() != 0) {
					    if (tasks.front() == "test") {
					       	// delete all of test 
						   while (tasks.size() != 0 && tasks.front() != "&&" && 
                               tasks.front() != "||" && tasks.front() != ";") { 
							   tasks.pop();
						   }
					}

					else if (tasks.front() != "&&" || tasks.front() != "||" ||
                            tasks.front() != ";") {
				 	        if (tasks.front() == "(") {
							int count = 1;
							tasks.pop();
							while (count != 0) {
								if (tasks.front() == "(") {
									count++;
								}
								else if (tasks.front() == ")") {
									count = count - 1;
								}
								tasks.pop();
						}
			  	        }
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
	//	    cout << "entered ( else if statement" << endl;
	//	    cout << comp_status << endl;
		    if (hash == 1)
		    {
			    perror("no connector before (");
			    exit(0);
		    }
		    tasks.pop();
		    int num = 1;
		    while (num != 0) {
	//		    cout << "entered the ( while statement" << endl;
			  //  cout << tasks.front() << endl;
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
				    if (num == 1) {
					    con.orr(tasks, comp_status2);
				    }

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
	//			    cout << "entered 2nd (" << endl;
				    tasks.pop();
				    num++;
			    }

			    else if (tasks.front() == ")") {
				    tasks.pop();

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
	//				    cout << "little exec2" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status10);
					    tasks.pop();
				    }
				    else if (num == 8) {
	//				    cout << "little exec2" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status9);
					    tasks.pop();
				    }
				    else if (num == 7) {
	//				    cout << "little exec2" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status8);
					    tasks.pop();
				    }
				    else if (num == 6) {
	//				    cout << "little exec2" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status7);
					    tasks.pop();
				    }
				    else if (num == 5) {
	//				    cout << "little exec2" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status6);
					    tasks.pop();
				    }
				    else if (num == 4) {
	//				    cout << "little exec2" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status5);
					    tasks.pop();
				    }
				    else if (num == 3) {
	//				    cout << "little exec2" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status4);
					    tasks.pop();
				    }
				    else if (num == 2) {
	//				    cout << "little exec2" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status3);
					    tasks.pop();
				    }

				    else if (num == 1) {
	//				    cout << "little exec1" << endl;
					    c = in.toChar(tasks.front());
					    ex.execute(c, comp_status2);
					    tasks.pop();
				    }
			    }
			    
			    if (tasks.size() == 0)
			    {
				    perror("not enough parentheses");
				    exit(0);
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
