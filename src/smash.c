/******************************************************************************
 * Emanuel Hernandez
 * Smash 3 project
 * 4/13/2018
******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "smash_utils.h"
#include "history.h"
#define MAX_SIZE_OF_LINE 2048

char *linecopy;
char *linecopy2;
int main (){
  initHistory();
  printf("%s\n",runSmashLoop());
  return 0;
}

struct myStruct {
  int tally;
  char **list;
}parse;

char *runSmashLoop(){
  int currentState;
  int lineSize = MAX_SIZE_OF_LINE;
  char line[lineSize];
  /*hardcode dollar sign*/
  fprintf(stderr,"%s","$");
  free(linecopy);
  while(fgets(line, lineSize, stdin) != NULL){
    line[strlen(line)-1] = '\0';  /*doesn't read newline character this way*/
    linecopy = (char*) malloc(sizeof(char)*MAX_SIZE_OF_LINE);
    strcpy(linecopy,line);
    struct historyStruct first = {linecopy};
    addHistory(first);
    char *token = strtok(line," ");
    tokenize(linecopy);
    currentState = useCommand(token);
    if(currentState == 1){
      return("Exiting Program...");
    }
    fprintf(stderr,"%s","$");
  }
  return(" ");
}

int useCommand(char *token){
  
  if(token == NULL){
    return 4;
  }
  else if(strcmp(token,"cd")==0){
    changeDir(token);
  }
  else if(strcmp(token,"exit")==0){
    if(exitSmash() == 5){
      return 1;
    }
  }
  else if(strcmp(token,"history")==0){
    printHistory();
  }
  else{
    const char* s = getenv("SMASH_KILL");
    if(s == NULL){ 
      chanceExecuteChild(token);
    }else{
      executeChild(token);
    }
  }
  return 0;
}

int tokenize(char *line){
  int i = 0;
  free(parse.list);
  free(linecopy2);
  parse.list = (char**)malloc(sizeof(char**) * 500);
  linecopy2 = (char*) malloc(sizeof(char)*MAX_SIZE_OF_LINE);
  strcpy(linecopy2,line);
  parse.list[i] = linecopy2;
  while(parse.list[i] !=  NULL){
    parse.list[++i] = strtok(NULL, " ");
  }
  parse.tally = i;
  return 6;
 free(linecopy);
}

int executeChild(char *token){
  pid_t pid;
  int status;
  
  pid = fork();

  if(pid < 0){
    perror("fork");
  }
  else if(pid == 0){
    if(execvp(token, parse.list) < 0){
      fprintf(stdout,"Command does not exist, please try again\n");
    }
    exit(0);
  }
  if(pid>0){
    if((pid = waitpid(pid,&status,0)) < 0){
      exitSmash();
    }
  }
  return 1;
}

int chanceExecuteChild(char *token){
  int chance = rand() % 4;
  
  if(chance!=0){
    executeChild(token);
    return 0;
  }
  else return 1;
}

int exitSmash(){
  free(parse.list);
  free(linecopy);
  free(linecopy2);
  clearHistory();
  return 5;
}

int changeDir(char *dir){
  
  if(chdir(parse.list[1])!=0){
    perror("Error ");
    return 1;
  }
  char* tempPtr;
  tempPtr = getcwd(NULL,FILENAME_MAX);
  printf("%s\n",tempPtr);
  free(tempPtr);
  return 2;
}

