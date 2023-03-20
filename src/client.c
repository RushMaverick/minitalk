#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("%s\n", "dude no");
		return (0);
	}
	kill(atoi(argv[1]), SIGUSR1); //Use to send signal to the PID
	
	return 0;
}