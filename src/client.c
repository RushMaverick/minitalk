#include <signal.h>
#include <stdio.h>
#include <unistd.h> //getpid, sleep
#include <stdlib.h>
#include "../includes/libft.h"

static void handle_string(int pid, char *msg)
{
	int bin_rep;
	int i;
	int finish;

	bin_rep = 0b10000000; 
			//	01000001
	i = 0;
	finish = 8;
	
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
	
	while(finish)
	{
		kill(pid, SIGUSR1);
		usleep(256);
		finish--;
	}
}

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("%s\n", "dude no");
		return (0);
	}
	handle_string(ft_atoi(argv[1]), argv[2]);
	
	return 0;
}