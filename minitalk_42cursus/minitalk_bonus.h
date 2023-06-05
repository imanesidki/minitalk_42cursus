/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:09:03 by isidki            #+#    #+#             */
/*   Updated: 2023/06/05 02:50:35 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

# define BOLD "\033[1m"
# define CYAN "\033[36m"

/**************************Utils******************************/
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_isdigit(int i);
/*************************************************************/

#endif
