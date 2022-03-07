/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:00:45 by hmanilow          #+#    #+#             */
/*   Updated: 2022/03/07 20:01:11 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check_ch(siginfo_t *siginfo, char res)
{
	if (!res)
	{
		kill (siginfo->si_pid, SIGUSR2);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

void	ft_receiving_bits(int signal, siginfo_t *siginfo, void *context)
{
	static int		j = 0;
	static pid_t	pid = 0;
	static char		res = 0;

	(void)context;
	if (pid != siginfo->si_pid)
	{
		j = 0;
		res = 0;
		pid = siginfo->si_pid;
	}
	res |= (signal == SIGUSR2);
	if (++j == 8)
	{
		write(1, &res, 1);
		if (ft_check_ch(siginfo, res))
			return ;
		j = 0;
		res = 0;
	}
	else
		res <<= 1;
	usleep(150);
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signal;

	ft_putstr("PID: ");
	ft_putnbr(getpid());
	write(0, "\n", 1);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = ft_receiving_bits;
	if (sigaction(SIGUSR1, &signal, 0))
	{
		ft_putstr("Wrong signal!\n");
		exit(2);
	}
	if (sigaction(SIGUSR2, &signal, 0))
	{
		ft_putstr("Wrong signal!\n");
		exit(2);
	}
	while (1)
		pause();
	return (0);
}
