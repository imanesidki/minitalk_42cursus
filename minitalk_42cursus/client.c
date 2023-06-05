/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:48:05 by isidki            #+#    #+#             */
/*   Updated: 2023/06/05 02:03:51 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_parsing(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (1);
	i = -1;
	while (av[1][++i])
	{
		if (!ft_isdigit(av[1][i]))
			return (1);
	}
	return (0);
}

static void	ft_get_char(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1 + (c >> i & 1));
		i--;
		usleep(600);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	if (ft_parsing(ac, av))
		return (-1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (-1);
	msg = av[2];
	i = 0;
	while (msg[i])
	{
		ft_get_char(msg[i], pid);
		i++;
	}
}
