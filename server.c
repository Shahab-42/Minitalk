/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuhamma <smuhamma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:42:09 by smuhamma          #+#    #+#             */
/*   Updated: 2023/01/29 17:50:02 by smuhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receiver(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "Server started - pid ", 22);
	ft_putnbr_fd(pid, 1);
	write(1, ". \n", 4);
	signal(SIGUSR1, receiver);
	signal(SIGUSR2, receiver);
	while (1)
		pause();
	return (0);
}
/*
client 
A - 65
0100 0010

0000 0000
0000 0001


1111 1111
1111 1111



0000 0000
0000 0000
0000 0001
0000 0010
*/
