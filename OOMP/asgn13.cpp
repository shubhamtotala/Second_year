/*----------------------------------------------------------
Name: Using multi-core programming implement a predicate class
Batch S-3
----------------------------------------------------------*/

// spawnexample.cpp
// Spawns a process, using the posix_spawn()
// function that calls the ps utility.

#include <spawn.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>
using namespace std;
int main()
{
	posix_spawnattr_t X;
	posix_spawn_file_actions_t Y;
	pid_t Pid;
	char *argv[] = {"/bin/ps","-lf",NULL};
	posix_spawnattr_init(&X);
	posix_spawn_file_actions_init(&Y);
	posix_spawn(&Pid,"/bin/ps", &Y,&X,argv,NULL);
	perror("posix_spawn");
	cout << "spawned PID: " << Pid <<endl;

	return(0);
}


/*----------------------------------------------------------

Output:
posix_spawn: Success
spawned PID: 8375
F S UID        PID  PPID  C PRI  NI ADDR SZ WCHAN  STIME TTY          TIME CMD
1 S student   1859     1  0  80   0 - 110617 poll_s 13:57 ?       00:00:00 /usr/
4 S student   1870  1336  0  80   0 - 99053 poll_s 13:57 ?        00:00:00 gnome
1 S student   1908  1870  0  80   0 -  3143 poll_s 13:58 ?        00:00:00 /usr/
1 S student   1911     1  0  80   0 -  6641 poll_s 13:58 ?        00:00:00 /usr/
1 S student   1912     1  0  80   0 -  6981 poll_s 13:58 ?        00:00:11 //bin
0 S student   1924  1870  0  80   0 - 170701 poll_s 13:58 ?       00:00:04 /usr/
0 S student   2004     1  0  80   0 - 13466 poll_s 13:58 ?        00:00:00 /usr/
0 S student   2006     1  0  80   0 - 86829 futex_ 13:58 ?        00:00:00 /usr/
0 S student   2012  1870  2  80   0 - 303038 poll_s 13:58 ?       00:02:47 compi
0 S student   2061  1870  0  80   0 - 110094 poll_s 13:58 ?       00:00:00 bluet
0 S student   2062  1870  0  80   0 - 146694 poll_s 13:58 ?       00:00:00 nm-ap
0 S student   2063  1870  1  80   0 - 348564 poll_s 13:58 ?       00:01:49 nauti
0 S student   2077     1  0  80   0 - 54869 poll_s 13:58 ?        00:00:00 /usr/
0 S student   2118  2012  0  80   0 -  1101 wait   13:58 ?        00:00:00 /bin/
1 S student   5938  5663  0  80   0 - 234421 futex_ 14:41 ?       00:00:00 /opt/
0 S student   6362  5649  0  80   0 - 95342 poll_s 14:56 ?        00:00:07 /opt/
1 S student   6366  6362  0  80   0 - 84702 wait_f 14:56 ?        00:00:00 /opt/
0 S student   6775     1  0  80   0 - 68453 poll_s 14:58 ?        00:00:00 /usr/
1 S student   7648  5663  0  80   0 - 241085 futex_ 15:15 ?       00:00:01 /opt/
0 S student   8264     1  0  80   0 -  4798 wait   15:31 ?        00:00:00 /usr/
0 S student   8280  8264 34  80   0 - 768798 futex_ 15:31 ?       00:00:23 /usr/
0 R student   8375     1  0  80   0 -  3820 -      15:33 ?        00:00:00 /bin/
---------------------------------------------------------*/



