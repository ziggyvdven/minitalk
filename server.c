/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:18:23 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/22 19:48:15 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"

int bit;

char	ft_btod(int num)
{
	int		decimal_num;
	int		base;
	int		rem;

	base = 1;
	decimal_num = 0;
	while (num > 0)
	{
		rem = num % 10;
		decimal_num = decimal_num + rem * base;
		num = num / 10;
		base = base * 2;
	}
	return (decimal_num);
}

void handle_sigusr1()
{
	bit = 0;
}

void handle_sigusr2()
{
	bit = 1;
}

int	main()
{
	struct sigaction	s1 = {0};
	struct sigaction	s2 = {0};
	pid_t				pid;
	char				byte[8];
	int 				i;

	i =	0;
	s1.sa_handler = &handle_sigusr1;
	s2.sa_handler = &handle_sigusr2;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s2, NULL);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		pause ();
		byte[i] = bit;
		i++;
		if(i == 7)
		{
			ft_printf("bit 7 = NULL\n");
			byte[7] = '\0';
			fflush(stdout);
			ft_printf("%s\n", byte);
			// ft_printf("byte = %d%d%d%d%d%d%d\n", byte[0],byte[1],byte[2],byte[3],byte[4],byte[5],byte[6]);
			i = 0;
		}
		usleep(200);
	}
}
