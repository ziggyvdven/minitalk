/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:18:23 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/05 20:40:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"
#include	<limits.h>

volatile char	g_bit;

void	handle_sigusr(int signal, siginfo_t *si, void *data)
{
	(void)data;
	(void)si;
	if (signal == SIGUSR1)
		g_bit = '0';
	else
		g_bit = '1';
}

int	ft_checkend(char *byte)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (byte[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_printbyte(char *byte)
{
	int				i;
	static int		end = 0;
	static char		buff[100000000000] = {0};
	static int		pos = 0;

	if (ft_checkend(byte) && end == 0)
	{
		buff[pos] = '\0';
		ft_putstr_fd(buff, 1);
		ft_putchar_fd('\n', 1);
		pos = 0;
		end = 1;
		return ;
	}
	i = ft_atoi(byte);
	i = ft_btod(i);
	if (end == 1)
		end = ft_makepid(byte, i);
	else
		buff[pos++] = (char)i;
}

int	ft_makepid(char *byte, int i)
{
	static char		pid[6] = {0};
	static int		pos = 0;

	if (ft_checkend(byte))
	{
		pid[pos] = '\0';
		kill (ft_atoi(pid), SIGUSR1);
		ft_bzero(pid, 6);
		pos = 0;
		ft_putstr_fd("SERVER PID: ", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	pid[pos++] = i;
	return (1);
}

int	main(void)
{
	struct sigaction	s1;
	char				byte[9];
	int					i;

	i = 0;
	ft_memset(&s1, 0, sizeof(s1));
	s1.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s1, NULL);
	ft_putstr_fd("SERVER PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		pause ();
		byte[i++] = g_bit;
		if (i == 8)
		{
			byte[8] = '\0';
			ft_printbyte(byte);
			i = 0;
		}
	}
	return (0);
}
