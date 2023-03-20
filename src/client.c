#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void *handle_string(int pid, char *msg)
{
	int bit;
	bit = 0x10000000;

	// while ();
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