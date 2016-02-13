# rshell
 We have made a basic command shell.
 It accepts both single commands and chained commands.
 The functionality of chained commands, however, are limited.
 The known errors regarding chained commands are:
 - does not ask for additional user input if input ends in && or ||
 - if && or || are not separated by spaces, the program will not recognize it
