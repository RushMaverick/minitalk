#include <stdio.h>
#include <signal.h>
#include <unistd.h> //getpid, sleep
#include <stdlib.h>

static void handle_string(int pid, char *msg)
{
	char bin_rep;
	int i;

	bin_rep = 0b10000000;
	i = 0;
	
	while (i != 8)
	{
		if ((msg[i] & bin_rep) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bin_rep = bin_rep >> 1;	// This is not causing it to loop. 
		i++;
	}
	i = 0;
	// while ();
}

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("%s\n", "dude no");
		return (0);
	}
	handle_string(atoi(argv[1]), argv[2]);
	
	return 0;
}