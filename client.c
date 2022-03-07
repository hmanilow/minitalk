/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:00:00 by hmanilow          #+#    #+#             */
/*   Updated: 2022/03/07 20:01:06 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_zero(int pid)
{
	int	j;

	j = 8;
	while (j--)
	{
		if (kill(pid, SIGUSR1))
			exit(1);
		usleep(800);
	}
}

void	ft_sending(int pid, char *text)
{
	int		j;
	char	s;

	while (*text)
	{
		s = *text;
		j = 8;
		while (j--)
		{
			if (s >> j & 1)
			{
				if (kill(pid, SIGUSR2))
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1))
					exit(1);
			}
			pause();
			usleep(150);
		}
		text++;
	}
	send_zero(pid);
}

void	ft_truth(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signal == SIGUSR2)
		ft_putstr("success\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;

	if (argc != 3)
		return (0);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = ft_truth;
	if (sigaction(SIGUSR2, &signal, 0))
	{
		ft_putstr("signal error\n");
		exit(2);
	}
	if (sigaction(SIGUSR1, &signal, 0))
	{
		ft_putstr("signal error\n");
		exit(2);
	}
	ft_sending(ft_atoi(argv[1]), argv[2]);
}
