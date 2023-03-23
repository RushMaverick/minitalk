#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "../includes/libft.h"

char *g_msg;

void sighandler(int sig)
{
	static int count = 0;
	static int bin_rep = 0b10000000;
	static char c = 0;
	static char ctostr[2]; 
	
	ctostr[1] = '\0';
	if (sig == SIGUSR2)
	{
		c = c | bin_rep;
	}
	bin_rep >>= 1;
	count++;
	if (count == 8)
	{ 
		ctostr[0] = c;
		g_msg = ft_strjoin(g_msg, ctostr);
		printf("ctorstr is: %s\n", ctostr);
		printf("g_msg is: %s\n", g_msg);
		count = 0;
		c = 0;
		bin_rep = 0b10000000;
	}
}

int main (void)
{
	int pid;
	g_msg = malloc(sizeof(char) * 2);
	if (!g_msg)
		return (0);
	struct sigaction sa;

	sa.sa_handler = &sighandler;
	sigemptyset(&(sa.sa_mask));
	sigaddset(&(sa.sa_mask), SIGUSR1);
	sigaddset(&(sa.sa_mask), SIGUSR2);
	sa.sa_flags = SA_RESTART;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();
	printf("PID is %d\n", pid);
	while (1)
	{
		pause();
	}
		
}