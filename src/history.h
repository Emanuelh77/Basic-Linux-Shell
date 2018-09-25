/*****************************************************************************
 * File: history.h
 * Author: Emanuel Hernandez
 * This file contains the declarations of 4 history.c functions
*****************************************************************************/


#include <stdio.h>
#include <string.h>
#include <unistd.h>


/*************************************************************************
 * Function: initHistory
 * Parameters: NONE
 * Initializes struct variables and pointer to a pointer char
 * Return value: NONE
*************************************************************************/
void initHistory();


/************************************************************************
 * Function: addHistory
 * Parameters: char* inCmd
 * Adds a line of input to the double pointer history.cmdList
 * Return value: NONE
************************************************************************/
void addHistory();


/************************************************************************
 * Function: printHistory
 * Parameters: NONE
 * Prints every line added to history.cmdList
 * Return value: 1
************************************************************************/
int printHistory();


/************************************************************************
 * Function: clearHistory
 * Parameters: NONE
 * Frees all memory malloc'ed
 * Return value: NONE
*************************************************************************/
void clearHistory();


/**********************************************************************
 *This is a struct stored in history.c with a character pointer
 *
**********************************************************************/
struct historyStruct{

  char* cmdList;
};
