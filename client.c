#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main (void)
{
	kill(6073, SIGKILL); //Use to send signal to the PID

	return 0;
}