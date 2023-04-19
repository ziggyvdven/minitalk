/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:54:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/19 15:36:23 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"

void	signal_send(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			kill (pid, SIGUSR1);
		if (str[i] == '1')
			kill (pid, SIGUSR2);
		usleep(150);
	i++;
	}
}

void	ft_sendend(int pid)
{
	int		i;

	i = 8;
	while (i)
	{
		kill (pid, SIGUSR1);
		usleep(50);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					binary;
	int					i;
	char				*binary_str;

	i = -1;
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][++i])
		{
			binary = ft_dtob(argv[2][i]);
			binary_str = ft_itoa_client(binary);
			signal_send(binary_str, pid);
			free(binary_str);
			binary_str = NULL;
		}
		ft_sendend(pid);
	}
	else
		ft_printf("Error try: client [the server PID] [The string to send]");
	return (0);
}
