/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:56:16 by isidki            #+#    #+#             */
/*   Updated: 2023/06/05 02:57:04 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	long long	n;
	long long	last;
	int			sign;

	sign = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		last = n;
		n = n * 10 + *str++ - '0';
		if (last != n / 10 && sign == 1)
			return (-1);
		else if (last != n / 10 && sign == -1)
			return (0);
	}
	return (n * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i < 10)
		ft_putchar(i + 48);
	if (i >= 10)
	{
		ft_putnbr((i / 10));
		ft_putnbr((i % 10));
	}
}

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}
