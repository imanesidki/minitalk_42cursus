/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:56:12 by isidki            #+#    #+#             */
/*   Updated: 2023/06/05 23:14:24 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_success(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message succesfully sent to the server\n", 39);
	}
	exit (0);
}

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
	char	*mssg;
	int		i;

	signal(SIGUSR1, send_success);
	if (ft_parsing(ac, av))
		return (-1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (-1);
	mssg = av[2];
	i = 0;
	while (mssg[i])
	{
		ft_get_char(mssg[i], pid);
		i++;
	}
	ft_get_char(255, pid);
	while (1)
		;
}
