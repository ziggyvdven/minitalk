/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:54:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/27 18:54:47 by zvan-de-         ###   ########.fr       */
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
		{
			kill (pid, SIGUSR1);
			usleep(50);
		}
		if (str[i] == '1')
		{
			kill (pid, SIGUSR2);
			usleep(50);
		}
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

void	ft_sendpid(int pid)
{	
	char	*pids;
	char 	*binary_str;
	int		binary;
	int		i;

	i = 0;
	pids = ft_itoa(getpid());
	while (pids[i])
	{
		binary = ft_dtob(pids[i]);
		binary_str = ft_itoa_client(binary);
		ft_printf("%s\n", binary_str);
		signal_send(binary_str, pid);
		i++;
	}
	ft_sendend(pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		binary;
	int		i;
	char	*binary_str;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][i])
		{
			binary = ft_dtob(argv[2][i]);
			binary_str = ft_itoa_client(binary);
			ft_printf("%s\n", binary_str);
			signal_send(binary_str, pid);
			i++;
		}
		ft_sendend(pid);
		ft_sendpid(pid);
	}
	else
	{
		ft_printf("Error: Incorrect number of parameters.\n");
		ft_printf("try: client [the server PID] [The string to send]");
	}
	return (0);
}
