//pipe4.cpp  (data producer)
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream> 

using namespace std;

int main(int argc,char *argv[])
{
    char data_processed;
    int file_pipes[2];
    char some_data[BUFSIZ + 1];
    char buffer[BUFSIZ + 1];
    char cmd[BUFSIZ + 1]; 
    pid_t fork_result;
    
    strcpy(cmd,argv[1]);
   for(int i=2; i<argc ;i++) //Concate the whole command to pass it onto pipe
  {
  	strcat (cmd," ");
  	strcat (cmd,argv[i]);
  }
 
    memset(buffer, '\0', sizeof(buffer));
 
    if (pipe(file_pipes) == 0) {   //creates pipe
        fork_result = fork();
        if (fork_result == (pid_t)-1) {  //fork fails
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
 
        if (fork_result == 0) {    //child
            sprintf(buffer, "%d", file_pipes[0]);
            (void)execl("pipe5", "pipe5", buffer, (char *)0);
            exit(EXIT_FAILURE);
        }
        else {                     //parent
            data_processed = write(file_pipes[1], cmd,
                                   strlen(cmd));
            printf("%d - wrote %d", getpid(), data_processed);
        }
    }
    exit(EXIT_SUCCESS);
}

