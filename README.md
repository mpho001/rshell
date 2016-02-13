# rshell
 We have made a basic command shell.
 It accepts both single commands and chained commands.
 In order to exit the shell, the user must type in "exit" either by itself
 or in a chained command where it won't be skipped.
 The && connector will only attempt to execute the next command only if the
 previous one was successful.
 The || connector will only attempt to execute the next command only if the
 previous one failed.
 The ; connector will always to attempt to execute the next command, if it
 exists.
 The functionality of chained commands, however, are limited.
 The known errors regarding chained commands are:
 - does not ask for additional user input if input ends in && or ||
 - if && or || are not separated by spaces, the program will not recognize it
 There are also some problems with bash script testing:
 - the bash script will not run properly if the while(1) loop in main isn't
   commented out
