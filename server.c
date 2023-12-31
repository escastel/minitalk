/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:54:21 by escastel          #+#    #+#             */
/*   Updated: 2023/11/15 12:34:46 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	action(int signal)
{
	static unsigned char	c;
	static int				i;

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
}

int	main(void)
{
	ft_printf("\x1b[33m" "The server PID is: %d\n" "\x1b[33m", getpid());
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
		pause();
	return (0);
}
