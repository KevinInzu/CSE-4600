#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
   pid_t pid;
	// make two process which run same
	// program after this instruction
  for(int i =0; i < 10; ++i)
  {
	if(pid = fork())
     	break;
  }
  printf("Parent of process:%d  is process:%d \n",pid,getpid());
 return 0;
}
