/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:18:23 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/29 17:45:46 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"

char	g_bit;

void	handle_sigusr1(int signal)
{
	(void) signal;
	g_bit = '0';
}

void	handle_sigusr2(int signal)
{
	(void) signal;
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
		ft_printf("\n");
		return ;
	}
	i = ft_atoi(byte);
	i = ft_btod(i);
	ft_printf("%c", i);
}

int	main(void)
{
	struct sigaction	s1;
	struct sigaction	s2;
	char				byte[9];
	int					i;

	i = 0;
	ft_memset(&s1, 0, sizeof(s1));
	ft_memset(&s2, 0, sizeof(s2));
	s1.sa_handler = &handle_sigusr1;
	s2.sa_handler = &handle_sigusr2;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s2, NULL);
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		pause ();
		byte[i] = g_bit;
		i++;
		if (i == 8)
		{
			ft_printbyte(byte);
			usleep(50);
			i = 0;
		}
	}
	return (0);
}
