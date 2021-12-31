/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:24:30 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/12/31 15:09:30 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_byte	g_byte;

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

void	send_bit(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill (pid, SIGUSR1) == -1)
		{
			write (1, "\033[0;31m\e[1mError!\n", 18);
			exit (EXIT_FAILURE);
		}
	}
	if (bit == 1)
	{
		if (kill (pid, SIGUSR2) == -1)
		{
			write (1, "\033[0;31m\e[1mError!\n", 18);
			exit (EXIT_FAILURE);
		}
	}
	usleep (200);
}

void	send_signal(int c, int pid)
{
	*(unsigned char *)&g_byte = (unsigned char)c;
	send_bit(g_byte.b1, pid);
	send_bit(g_byte.b2, pid);
	send_bit(g_byte.b3, pid);
	send_bit(g_byte.b4, pid);
	send_bit(g_byte.b5, pid);
	send_bit(g_byte.b6, pid);
	send_bit(g_byte.b7, pid);
	send_bit(g_byte.b8, pid);
}

void	handler(int signum)
{
	(void)signum;
	write (1, "\033[0;32m\e[1mSuccessfully recieved by the server!\n", 48);
	exit (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		signal (SIGUSR1, handler);
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write (1, "\033[0;31m\e[1mBad PID!\n", 20);
			return (0);
		}
		while (av[2][i])
		{
			send_signal(av[2][i], pid);
			i++;
		}
		i = -1;
		while (++i < 9)
			send_bit(0, pid);
	}
	else
		write (1, "Usage: ./client [PID] [STRING]\n", 31);
	return (0);
}
