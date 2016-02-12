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

    bool completion_status;
    char** c = NULL;
    Execute ex;
    //bool worked = true;
    while (tasks.size() != 0) {
        // if at any point the user has exit
        if (tasks.front() == "exit") {
            exit(0);
        }

        else if (tasks.front() == "&&")
       	{
	    
		tasks.pop(); //gets rid of the &&
            // if the command before this one does returns false then we dont do            //the next command
	    if(completion_status == false)
	    {
		  // so the && connector should have already been deleted, this is a while loop to delete the next commands so that they wont run if the command before fails  
		  while(tasks.front() != "&&" || tasks.front() != "||" || tasks.front() != ";")
		  {
			 tasks.pop();
		  }
		  // here we would just assign completition status false again to mafe sure that the next connector know that it failed
		  completion_status = false;
	    }
	
	    // here we just run the next command like normal
	    if(completion_status == true)
	    {
		    c = in.toChar(tasks.front());
		    completion_status = ex.execute(c);
		    tasks.pop();
	    }
        }

        else if (tasks.front() == "||") 
	{
		cout << "u ";
	    tasks.pop();  // gets rid of the ||
	   cout << "wass up "; 
            if(completion_status == true)
	    {

		cout << "what ";	    
		  if(tasks.size() != 0)
		  {
			  cout << "j ";
			  if (tasks.front() != "&&" || tasks.front() != "||" || tasks.front() != ";")
			  {
				  cout << "hi ";
				 tasks.pop();
			  }
		  }
		  // here we would just assign completition status true again to make sure that the next connector knows that it 
		  completion_status = false;
	    }

	    // if its false then for || it should run
	    if(completion_status == false)
	    {	    
		    c = in.toChar(tasks.front());
		    completion_status = ex.execute(c);
		    tasks.pop();
	    }

        }

       // else if (tasks.front() == ";") {
        //    // do something else, son
       // }
        
        // if not a connector or exit, then execute it 
        else {
            c = in.toChar(tasks.front());
            completion_status = ex.execute(c);
		cout << "hey ";
	    tasks.pop();
	    cout << "work ";
        }
    }

    cout << flush;

    }

    return 0;

}
