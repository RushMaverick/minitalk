/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:09:00 by rrask             #+#    #+#             */
/*   Updated: 2023/03/29 10:40:22 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "minitalk_bonus.h"

static const char	*g_msg;

void	sighandler(int sig, siginfo_t *siginfo, void *lucas)
{
	static int	count = 0;
	static int	bin_rep = 0b10000000;
	static char	c = 0;
	static char	ctostr[2];

	ctostr[1] = '\0';
	if (sig == SIGUSR2 && (lucas || !lucas))
		c = c | bin_rep;
	bin_rep >>= 1;
	if (++count == 8)
	{
		ctostr[0] = c;
		if (c == '\0')
		{
			ft_printf("%s", g_msg);
			free((void *)g_msg);
			kill(siginfo->si_pid, SIGUSR1);
			g_msg = ft_strdup("");
		}
		else
			g_msg = ft_strjoin(g_msg, ctostr);
		count = 0;
		c = 0;
		bin_rep = 0b10000000;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	g_msg = malloc(sizeof(char) * 2);
	if (!g_msg)
		return (0);
	sa.sa_sigaction = &sighandler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("PID is %d\n", pid);
	while (pause())
		;
	return (0);
}
