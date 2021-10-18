 int main()
{
 stack<int> stck;
 pid_t pid;
  const char *message;
  int n, exit_code;
  string str;
  cout << "fork program starting\n";  
  pid = fork();
  switch(pid){
  case -1:
  	cout << "Fork failure!\n";
  	return 1;
  case 0:
  	stck.push(getpid());
  	stck.push(getppid());
        str = "this is the child \n";
        message = const_cast<char*>(str.c_str());
        pid = fork();  // create child within child
        n = 5;
        exit_code=9;
        break;
  default:
        str = "this is the parent \n";
        message =  const_cast<char*>(str.c_str());
        n = 3;
        exit_code = 0;
        break;      	
}
for (int i=0; i < n; ++i){
	cout << message;
	sleep(1);
} // waiting for child to finish
if(pid != 0){ // parent 
   int stat_val;
   pid_t child_pid;
   child_pid = wait(&stat_val); // wait for child
   cout << "Child finished: PID = " << child_pid << endl;
   if(WIFEXITED (stat_val))
      cout << "child exited with code: " << WEXITSTATUS(stat_val) << endl;
   else
      cout << "child terminated abnormally!" << endl;   
} // waiting for grandchild to finish
if(pid ==0) { // child
  int stat_val1;
  pid_t gc_pid;
  gc_pid = wait(&stat_val1); // wait for grandchild
  cout << "GrandChild finished: PID =" << gc_pid << "\t";
  cout << "Child_PID= " << stck.top() << "\t";
  stck.pop();
  cout << "Parent_PID = " << stck.top() << endl;
  if(WIFEXITED(stat_val1))
     cout <<"Grandchild exited with code:" << WEXITSTATUS(stat_val1)<< endl;
  else
     cout << "Grandchild terminated abnormally!" << endl;
}
exit(exit_code);
}
