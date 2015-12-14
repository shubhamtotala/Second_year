/*--------------------------------------------------------PROGRAM NAME:Implement POSIX semaphore using multi-core programming
-------------------------------------------------------*/


#include <pthread.h>
#include <stdlib.h>
#include<iostream>
#include <stdio.h>
using namespace std;

int  SIZE;      //Size by SIZE matrices
int num_thrd;   // number of threads
int A[20][20],B[20][20],C[20][20]; // initialize a matrix
void init_matrix(int m[20][20],int SIZE)
{
	int i, j, val = 0;
  	for (i = 0; i < SIZE; i++)
  	{
    		for (j = 0; j < SIZE; j++)
    		{
			cout<<"\nEnter value for row "<< i << " &  col " << j;
			cin>>m[i][j];
     		}
  	}
}

void print_matrix(int m[20][20],int SIZE)
{
  int i, j;
  for (i = 0; i < SIZE; i++) {
    printf("\n\t| ");
    for (j = 0; j < SIZE; j++)
      printf("%2d ", m[i][j]);
    printf("|");
  }
}

// thread function: taking "slice" as its argument
void* multiply(void* slice)
{
  long s = (long)slice;   // retrive the slice info
  long from = (s * SIZE)/num_thrd; // note that this 'slicing' works fine
  long to = ((s+1) * SIZE)/num_thrd; // even if SIZE is not divisible by num_thrd
  int i,j,k;

 printf("Slice = %ld \n",s);

  for (i = from; i < to; i++)
  {
    for (j = 0; j < SIZE; j++)
    {
      C[i][j] = 0;
      for ( k = 0; k < SIZE; k++)
 C[i][j] += A[i][k]*B[k][j];
    }
  }
  printf("finished slice %ld\n", s);
  return 0;
}

int main(int argc, char* argv[])
{
  pthread_t *thread;  // pointer to a group of threads
  cpu_set_t cpu1[2];
  long i;
  int thr[10],temp;
  int s;


  cout<<"Enter Size of matrix";
  cin>>SIZE;

  if (argc!=2)
  {
    printf("Usage: %s number_of_threads\n",argv[0]);
    exit(-1);
  }

  num_thrd = atoi(argv[1]);
  cout<<"\n\nEnter values for first matrix:";
  init_matrix(A,SIZE);
  cout<<"\n\nEnter values for second matrix:";
  init_matrix(B,SIZE);


  cout<<"\n\n=>";
  cout<<num_thrd+ "\n";


   thread = (pthread_t*)malloc(num_thrd*sizeof(pthread_t));

     cout<<"\n Test2";
  // this for loop not entered if threadd number is specified as 1

  for (i = 1; i < num_thrd; i++)
  {

// creates each thread working on its own slice of i
	cout<<"\n Test 1 for\n";
    	thr[i] = pthread_create (&thread[i], NULL, multiply, (void*)i);

	if (thr[i] != 0 )
    	{
      		perror("Can't create thread");
      		free(thread);
      		exit(-1);
    	}

	CPU_ZERO(&cpu1[i]);
	CPU_SET(i,&cpu1[i]);
    	pthread_setaffinity_np(thread[i], sizeof(cpu_set_t), &cpu1[i]);
  }

  // main thread works on slice 0
  // so everybody is busy
  // main thread does everything if threadd number is specified as 1

  multiply(0);

  // main thead waiting for other thread to complete
  for (i = 1; i < num_thrd; i++)
 	pthread_join (thread[i], NULL);
	  printf("\n\n");
	  print_matrix(A,SIZE);
	  printf("\n\n\t       * \n");
	  print_matrix(B,SIZE);
	  printf("\n\n\t       = \n");
	  print_matrix(C,SIZE);
	  printf("\n\n");
	  free(thread);


  return 0;

}

/*------------------OUTPUT-------------------------------
save this assignment in Home(ubuntu) using gedit (DONT USE ECLIPSE)
and run on Teminal as follows
Output:-


ubuntu@ubuntu-OptiPlex-3010:~$ g++ -o asgn15.out asgn15.cpp -lpthread
ubuntu@ubuntu-OptiPlex-3010:~$ ./asgn15.out 2
Enter Size of matrix2


Enter values for first matrix:
Enter value for row 0 &  col 0 2

Enter value for row 0 &  col 1 2

Enter value for row 1 &  col 0 3

Enter value for row 1 &  col 1 3


Enter values for second matrix:
Enter value for row 0 &  col 0 3

Enter value for row 0 &  col 1 3

Enter value for row 1 &  col 0 4

Enter value for row 1 &  col 1 6


=>
 Test2
 Test2
 Test 1 for
Slice = 0 
finished slice 0
Slice = 1 
finished slice 1



	|  2  2 |
	|  3  3 |

	       * 

	|  3  3 |
	|  4  6 |

	       = 

	| 14 18 |
	| 21 27 |

ubuntu@admin12:~$ 
--------------------------------------------------------*/
