#include <stdio.h>
#include <signal.h>
#include <unistd.h>

char *msg;

void sighandler(int sig)
{
	static char c = 0;
	static int count = 0;
	static int bin_rep = 0b10000000;

	if (sig == SIGUSR2)
	{
		c = c | bin_rep;
	}
	bin_rep >>= 1;
	count++;
	if (count == 8)
		printf("%c", c);
	// printf("%c\n", c);
}

int main (void)
{
	int pid;

	struct sigaction sa;

	sa.sa_handler = &sighandler;
	sigemptyset(&(sa.sa_mask));
	sigaddset(&(sa.sa_mask), SIGUSR1);
	sigaddset(&(sa.sa_mask), SIGUSR2);
	sa.sa_flags = 0;
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();
	printf("PID is %d\n", pid); // 22.03 If I have this in the while loop it works
	while (1)
	{
		pause();
		// usleep(500);
	}
		
}
