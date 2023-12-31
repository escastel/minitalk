/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:32:59 by escastel          #+#    #+#             */
/*   Updated: 2023/11/15 12:23:43 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	send_signal(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) % 2 == 1)
			kill(pid, SIGUSR1);
		else if ((c >> i) % 2 == 0)
			kill(pid, SIGUSR2);
		usleep(75);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("\x1b[31m" "Incorrect format\n" "\x1b[31m");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, (unsigned char)argv[2][i]);
		i++;
	}
	send_signal(pid, '\0');
	ft_printf("\n");
	return (0);
}
