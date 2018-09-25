/***************************************************************************
 * Emanuel Hernandez
 * History file
 * 3/23/18
***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "history.h"

static struct historyStruct* history;

static int atIndex;
static int size;

void initHistory(){
  atIndex = 0;
  size = 500;
  history = (struct historyStruct*) malloc(sizeof(struct historyStruct)*size);
}

void addHistory(struct historyStruct hist){
  if(atIndex < size){
    history[atIndex] = hist;
    atIndex++;
  }
  else clearHistory();
}

void clearHistory(){
  free(history);
}

int printHistory(){
  int p = 0;
  while(p < atIndex){
    printf("[%d] %s\n",p,history[p].cmdList);
    p++;
  }
  return 2;
}


