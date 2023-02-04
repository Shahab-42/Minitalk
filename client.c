/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuhamma <smuhamma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:42:01 by smuhamma          #+#    #+#             */
/*   Updated: 2023/01/29 17:29:44 by smuhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_data(char c, int pid)
{
	int	i;
	int	j;

	i = 128;
	j = 0;
	while (i > 0)
	{
		if ((c & i) == i)
			j = kill(pid, SIGUSR1);
		else
			j = kill(pid, SIGUSR2);
		i = i / 2;
		usleep(100);
	}
	ft_check_error("", j);
}

int	main(int ac, char **av)
{
	int	i;
	int	s;

	i = 0;
	if (ac == 3)
	{
		s = ft_atoi(av[1]);
		while (av[2][i])
			send_data(av[2][i++], s);
		send_data('\0', s);
	}
	else
		write(1, "Error : Format ./client <server_pid> <message>\n", 48);
}
