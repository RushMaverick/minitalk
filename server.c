#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main (void)
{
	int pid;

	pid = getpid();
	while (pid)
		printf("PID is %d\n", pid);
	return 0;
}