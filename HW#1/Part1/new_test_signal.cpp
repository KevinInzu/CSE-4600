//test_signal.cpp
#include <signal.h>
#include <unistd.h>
#include <iostream>
 
using namespace std;
 
void func (int sig)
{
  cout << "Oops! -- I got a signal " << sig << endl;
}
 
int main()
{
  struct sigaction sigbreak;
 
  (void) signal (SIGINT, func);    //catch terminal interrupts
  sigemptyset(&sigbreak.sa_mask);  // Sigbreak is class, sa_mask is variable which is the set of signals that we want delete
  sigaction (SIGINT,&sigbreak,NULL);
  
  

  
  while (1){
    cout << "CSUSB CSE 4600 Operating Systems. Homework on signals" << endl;
    sleep (1); 
  }
  return 0;
}

