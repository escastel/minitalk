/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:06:55 by escastel          #+#    #+#             */
/*   Updated: 2023/11/15 12:46:14 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	action(int signal, siginfo_t *si, void *ctx)
{
	static unsigned char	c;
	static int				i;

	(void) ctx;
	c = c | (signal == SIGUSR1);
	i++;
	if (i != 8)
		c = c << 1;
	else
	{
		if (c != '\0')
			ft_printf("\x1b[0m" "%c" "\x1b[0m", c);
		else
			ft_printf("\n");
		i = 0;
		c = 0;
	}
	if (signal == SIGUSR1)
		kill(si->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill (si->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("\x1b[33m" "The server PID is: %d\n" "\x1b[33m", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
