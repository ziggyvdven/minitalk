/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:18:23 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/05 15:11:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"

char	g_bit;

void	handle_sigusr(int signal, siginfo_t *info, void *null)
{
	(void)null;
	(void)info;
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

	byte[8] = '\0';
	if (ft_checkend(byte))
	{
		printf("\n");
		return ;
	}
	i = ft_atoi(byte);
	i = ft_btod(i);
	ft_printf("%c", i);
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
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		pause ();
		byte[i] = g_bit;
		if (i == 8)
		{
			ft_printbyte(byte);
			i = 0;
		}
		i++;
	}
	return (0);
}
