/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:08:55 by rrask             #+#    #+#             */
/*   Updated: 2023/03/29 10:40:13 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "minitalk.h"

static void	msghandler(int pid, char *msg)
{
	static int	bin_rep = 0b10000000;
	static int	i = 0;

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

static void	handle_string(int pid, char *msg)
{
	int	finish;

	finish = 8;
	msghandler(pid, msg);
	while (finish)
	{
		kill(pid, SIGUSR1);
		usleep(256);
		finish--;
	}
}

static void	sighandler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message sent success");
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*msg;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("No arguments given or too many, idk.\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0 || kill(pid, 0) == -1)
	{
		ft_printf("Invalid PID\n");
		return (0);
	}
	msg = argv[2];
	sa.sa_handler = &sighandler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	handle_string(pid, msg);
	return (0);
}
