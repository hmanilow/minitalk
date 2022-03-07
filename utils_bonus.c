/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:00:52 by hmanilow          #+#    #+#             */
/*   Updated: 2022/03/07 20:01:11 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	number;

	if (n < 0)
	{
		write(1, "-", 1);
		number = (unsigned int)(-1 * n);
	}
	else
		number = (unsigned int)n;
	if (number >= 10)
		ft_putnbr(number / 10);
	ft_putchar((char)(number % 10 + '0'));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_atoi(const char *str)
{
	int				znak;
	long long int	result;

	znak = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		znak = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (znak * result > 2147483647)
			return (-1);
		if (znak * result < -2147483648)
			return (0);
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * znak);
}
