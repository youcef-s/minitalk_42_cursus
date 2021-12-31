/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:58:12 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/12/31 15:07:47 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_byte	g_byte;

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write (1, &c, 1);
	}
}

void	set_bit(int bit, int *i)
{
	if (*i == 1)
		g_byte.b1 = bit;
	if (*i == 2)
		g_byte.b2 = bit;
	if (*i == 3)
		g_byte.b3 = bit;
	if (*i == 4)
		g_byte.b4 = bit;
	if (*i == 5)
		g_byte.b5 = bit;
	if (*i == 6)
		g_byte.b6 = bit;
	if (*i == 7)
		g_byte.b7 = bit;
	if (*i == 8)
	{
		g_byte.b8 = bit;
		write (1, &*(unsigned char *)&g_byte, 1);
		*i = 0;
	}
	(*i)++;
}

void	sig_handler(int signum)
{
	static int	i;

	if (!i)
		i = 1;
	if (signum == SIGUSR1)
		set_bit(0, &i);
	if (signum == SIGUSR2)
		set_bit(1, &i);
}

int	main(void)
{
	struct sigaction	s_act;

	s_act.sa_handler = &sig_handler;
	s_act.sa_flags = SA_RESTART;
	sigemptyset(&s_act.sa_mask);
	sigaddset(&s_act.sa_mask, SIGUSR1);
	sigaddset(&s_act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &s_act, NULL);
	sigaction(SIGUSR2, &s_act, NULL);
	write (1, "PID: ", 6);
	ft_putnbr(getpid());
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
