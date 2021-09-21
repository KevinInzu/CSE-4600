
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
 
using namespace std;
 
int main(int argc, char *argv[])
{
  FILE *fpi;                //for reading a pipe
 
  char buffer[BUFSIZ+1];        //BUFSIZ defined in <stdio.h>
  char cmd[BUFSIZ+1]; 		 // Make OS assign memory
  
  int chars_read;
  
  strcpy(cmd,argv[1]);	//Move argv command line into cmd
  
  for(int i=2; i<argc ;i++) //Concate the whole command to pass it onto pipe
  {
  	strcat (cmd," ");
  	strcat (cmd,argv[i]);
  	cout << cmd << endl;
  }
  
  memset (buffer, 0,sizeof(buffer));    //clear buffer
  fpi = popen (cmd, "r");    //pipe to command "ps -auxw"
  if (fpi != NULL) {
    //read data from pipe into buffer
    chars_read = fread(buffer, sizeof(char), BUFSIZ, fpi);  
    if (chars_read > 0) 
     cout << "Output from pipe: " << buffer << endl;
    pclose (fpi);             //close the pipe
    return 0; 
  }
 
  return 1;
}
 


