/************************************************************************
 * File: smash_utils.h
 * Author: Emanuel Hernandez
 * This file contains the declarations of smash functions
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/***********************************************************************
 * Function: ruSmashLoop
 * Parameters: none
 * Runs a loop reading lines in and tokenizes them
 * Return value: "Exiting Program" once the user is done with it
***********************************************************************/
char *runSmashLoop();

/***********************************************************************
 * Function: useCommand
 * Parameters: char *token
 * Changes directory, exits the shell script or prints anything else
 * word by word and line by line
 * Return value: 3 if the first token is equal to cd, 2 if getcwd's
 * result is unknown, 1 if user exits the shell script and 0 for 
 * anything else
***********************************************************************/
int useCommand();

/***********************************************************************
 * Function: tokenize
 * Parameters: char *line
 * Adds input to char **list and prints out input if the first token is
 * not cd, exit or history
 * Return value: 6
***********************************************************************/
int tokenize();

/***********************************************************************
 * Function: changeDir
 * Parameters: char *dir
 * Changes directory to specified directory or prints error with the
 * perror function
 * Return value: 1 if error occurs
***********************************************************************/
int changeDir();

/***********************************************************************
 * Function: exitSmash
 * Parameters: none
 * Exits smash
 * Return value: 5
***********************************************************************/
int exitSmash();

/***********************************************************************
 * Function: executeChild
 * Parameters: char *token
 * Executes the command of child process
 * Return value: 1
***********************************************************************/
int executeChild();

/***********************************************************************
 * Function: chanceExecuteChild
 * Parameters: char *token
 * Executes the command of child process 75% of the time
 * Return value: 5
***********************************************************************/
int chanceExecuteChild();





