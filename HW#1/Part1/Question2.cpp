 #include <unistd.h>
#include<iostream>
using namespace std;
int main()
{
cout << “running ps with execl” << endl;
execl(“/bin/ps”, “/bin/ps”, “-ax”, NULL);
cout << “the program is exiting” << endl;
return 0;
}
