#include <signal.h>
#include <stdio.h>
#include <unistd.h> //getpid, sleep
#include <stdlib.h>
#include "../includes/libft.h"

static void msghandler(int pid, char *msg)
{
	static int bin_rep = 0b10000000;
	static int i = 0;

	while (*msg != '\0')
	{
		while (i != 8)
		{
			if ((*msg & bin_rep >> i) == 0)
			{
				kill(pid, SIGUSR1);
				usleep(256);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(256);
			}
			i++;
		}
		i = 0;
		msg++;
	}
}

static void handle_string(int pid, char *msg)
{
	int finish;

	finish = 8;
	msghandler(pid, msg);
	while(finish)
	{
		kill(pid, SIGUSR1);
		usleep(256);
		finish--;
	}
}

int main (int argc, char *argv[])
{
	int pid;
	char *msg;

	if (argc <= 1)
	{
		ft_printf("%s\n", "No arguments given.");
		return (0);
	}

	pid = ft_atoi(argv[1]);
	msg = argv[2];

	if (argc <= 2)
	{
		ft_printf("%s\n", "Remember to attach a message.");
		return (0);
	}
	if (kill(pid, 0) == -1)
		ft_printf("%s\n", "Invalid PID.");
	handle_string(pid, msg);
	
	return (0);
}