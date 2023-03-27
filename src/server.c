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
		c = c | bin_rep;
	bin_rep >>= 1;
	count++;
	if (count == 8)
	{
		ctostr[0] = c;
		if (c == '\0')
		{
			ft_printf("%s\n", g_msg); //CHANGE TO OWN PRINTF
			free(g_msg);
		}
		g_msg = ft_strjoin(g_msg, ctostr);
		count = 0;
		c = 0;
		bin_rep = 0b10000000;
	}
}

int main (void)
{
	int pid;
	struct sigaction sa;

	g_msg = malloc(sizeof(char) * 2);
	if (!g_msg)
		return(0);
	sa.sa_handler = &sighandler;

	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();
	ft_printf("PID is %d\n", pid);
	while (pause())
	{

	}
}
