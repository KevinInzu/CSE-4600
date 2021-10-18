Answer:
 #include <pthread.h>
#include <stdio.h>
using namespace std;
//The thread for first one
void*runner_thread1(void*data)
{
printf("Thread one started\n");
 pthread_exit ( 0 );
}
//The thread for second one
void *runner_thread2( void *data)
{
   printf("Thread two started\n");
   pthread_exit ( 0 );
}
//The thread for third one
void *runner_thread3( void *data)
{
    printf("Thread three started\n");
    pthread_exit ( 0 );
}
int main()
{
   pthread_t id1, id2, id3;    //thread identifiers. id3 is thread identifier for third thread
   pthread_attr_t attr1, attr2, attr3; //set of thread attributes. attr3 is thread attribute for third thread
    pthread_attr_init ( &attr1 );
    pthread_attr_init ( &attr2 );
   pthread_attr_init ( &attr3 ); //for the new thread
   void *data;   //a pointer to give as parameter to function
   //create the thread
   pthread_create ( &id1, &attr1, runner_thread1 , data );
   pthread_create ( &id2, &attr2, runner_thread2 , data );
   pthread_create ( &id3, &attr3, runner_thread3 , data ); //for the new thread
   //wait for the thread to exit
   pthread_join( id1, NULL );
   pthread_join( id2, NULL );
   pthread_join( id3, NULL ); //for the new thread
   return 0;
}
