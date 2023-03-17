#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main (__attribute__ ((unused)) int argc, char *argv[])
{
	kill(atoi(argv[1]), SIGKILL); //Use to send signal to the PID

	return 0;
}