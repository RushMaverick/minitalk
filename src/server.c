#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig1handler(__attribute__ ((unused))int sig)
{
	printf("%s\n", "I have handled SIGUSR1");
}

void sig2handler(__attribute__ ((unused))int sig)
{
	printf("%s\n", "I have handled SIGUSR2");
}

int main (void)
{
	struct sigaction sa;
	sa.sa_handler = &sig1handler;
	// sa.sa_handler = &sig2handler;
	sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	int pid;

	pid = getpid();
	while (pid)
	{
		printf("PID is %d\n", pid);
		sleep(2);
	}
	return 0;
}