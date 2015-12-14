/*--------------------------------------------------------
Program Name:Implement POSIX queue class that encapsulates the basic function such as open,
send, receive, remove, close. Use multi-core programming
-------------------------------*/


#include<iostream>
#include<pthread.h>
#include<stdlib.h>
using namespace std;

int ct = 0;

void *task1(void *X)
{
	int *temp;
	temp = static_cast <int * > (X);
	cout<<"\n work from thread: "<<endl;
 	cout<<"\n Thread complete"<<endl;
 	return (NULL);
 }

 int main(int argc, char *argv[])
{
 	int N;
 	pthread_t MyThreads[10];
 	if(argc != 2){
 		cout<<"error"<<endl;
 		exit (1);
 	}
 	N = atoi(argv[1]);
	if(N > 10){
		N = 10;
 	}
 	for(int count = 0;count < N;count++)
 	{
 		pthread_create(&MyThreads[count],NULL,task1,&N);

 	}
 	for(int count = 0;count < N;count++)
 	{
 		pthread_join(MyThreads[count],NULL);
 	}
 	return(0);
}

/*--------------------------OUTPUT------------------------

save this assignment in Home(ubuntu) using gedit (DONT USE ECLIPSE)
and run on Teminal as follows
Output:-


ubuntu@ubuntu-OptiPlex-3010:~$ g++ -o asgn14.out asgn14.cpp -lpthread
ubuntu@ubuntu-OptiPlex-3010:~$ ./asgn14.out 4

work from thread:
work from thread:

Thread complete

work from thread:

Thread complete


Thread complete
work from thread:

Thread complete

ubuntu@ubuntu-OptiPlex-3010:~$
--------------------------------------------------------*/




