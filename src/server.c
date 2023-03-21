#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig1handler(__attribute__((unused))int sig)
{
	printf("%s\n", "I have handled SIGUSR1");
}

void sig2handler(__attribute__((unused))int sig)
{
	printf("%s\n", "I have handled SIGUSR2");
}

int main (void)
{
	struct sigaction sa;

	sa.sa_handler = &sig1handler;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = 0;

	sa.sa_handler = &sig2handler;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = 0;

	int pid;

	pid = getpid();
	while (1)
	{
		printf("PID is %d\n", pid);
		pause();
	}
}
