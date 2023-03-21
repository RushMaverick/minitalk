#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sighandler(int sig)
{
	if (sig == SIGUSR1)
		printf("%s\n", "that's a 0");
	if (sig == SIGUSR2)
		printf("%s\n", "that's a 1");
	
}

int main (void)
{
	int pid;

	struct sigaction sa;

	sa.sa_handler = &sighandler;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = 0;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();
	while (1)
	{
		printf("PID is %d\n", pid);
		pause();
	}
}
