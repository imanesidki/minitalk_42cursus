/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:55:52 by isidki            #+#    #+#             */
/*   Updated: 2023/06/05 02:55:57 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handel(int sig, siginfo_t *info, void *cont)
{
	static unsigned char	c;
	static int				i;
	static int				pid;

	(void)cont;
	if (pid != info->si_pid)
		pid = info->si_pid;
	c = (c << 1) | (sig & 1);
	i++;
	if (i == 8)
	{
		if (c == 255)
			kill(info->si_pid, SIGUSR1);
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sigac;

	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = handel;
	sigaction(SIGUSR1, &sigac, NULL);
	sigaction(SIGUSR2, &sigac, NULL);
	write(1, CYAN BOLD "Server started!\nPID: ", 30);
	ft_putnbr(getpid());
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
