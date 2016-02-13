# Melinda and Niharika's Wondrous rshell

### Shell.h 
 We have made a basic command shell.
 It accepts both single commands and chained commands.
 In order to exit the shell, the user must type in "exit" either by itself
 or in a chained command where it won't be skipped.

### Input.cpp
 In Input.cpp we take in and parse through the user given command line and store the command s in a queue of strings called tasks.
 
### main.cpp
 We established identifying our connectors in the main. We have a queue of strin gs called tasks, which stores our parse results. Then we go through each elemet and check whether it is one of our connectors or just a command to be executed. We then have if and else statements that carry out these steps. 

### Execute.cpp
 We wanted our execute to return whether a function had executed properly or not thus we had a bool parameter by reference (from the main) which we called ***co mp_status***. Originally we just a ssigned ***comp_status*** true or false by a assigning it in our child with an if loop when the child did not work (we would then assign ***comp_status*** false). But this created problems because we coul could not get the same assignment in our parent. We ended up making out exit re turn an "**unsuccessful completion** if it did command could not be executed, m meaning we had a number greater than zero in our exit. After the parent finishe d we would unscramble that number with *WEXITSTATUS* and assign it true or fals e depending on if that number was 0(true) or false(in our case, we chose the nu mber 69).    

### Bugs
 The functionality of chained commands, however, are limited.
 Our known bugs are:
 - If the input ends in && or ||, our bash does not ask for additional user input
 - If the && or || connectors are not separated by spaces, the program will not recognize it
 - The bash script will not run properly if the while(1) loop in main isn't commented out.
