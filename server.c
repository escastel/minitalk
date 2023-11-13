/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:54:21 by escastel          #+#    #+#             */
/*   Updated: 2023/11/13 16:43:14 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_server(int signal)
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
			ft_printf("%c", c);
		else
			ft_printf("\n");
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("The server PID is: %d\n", getpid());
	signal(SIGUSR1, ft_server);
	signal(SIGUSR2, ft_server);
	while (1)
		pause();
	return (0);
}

