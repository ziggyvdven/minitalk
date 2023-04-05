/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:54:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/05 12:54:22 by zvan-de-         ###   ########.fr       */
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
		usleep(250);
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

void	handle_sigusr1(int signal)
{
	(void) signal;
	ft_printf("Message recieved\n");
	exit (0);
}

void	ft_sendpit(int pid)
{
	int		i;
	int		binary;
	char	*binary_str;
	char	*pids;

	i = 0;
	pids = ft_itoa(getpid());
	while (pids[i])
	{
		binary = ft_dtob(pids[i]);
		binary_str = ft_itoa_client(binary);
		signal_send(binary_str, pid);
		i++;
	}
	ft_sendend(pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	s1;
	int					pid;
	int					binary;
	int					i;
	char				*binary_str;

	i = -1;
	ft_memset(&s1, 0, sizeof(s1));
	s1.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &s1, NULL);
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][++i])
		{
			binary = ft_dtob(argv[2][i]);
			binary_str = ft_itoa_client(binary);
			signal_send(binary_str, pid);
		}
		ft_sendend(pid);
	}
	else
		ft_printf("Error try: client [the server PID] [The string to send]");
	return (0);
}
