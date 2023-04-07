/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:54:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/06 16:23:20 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"

volatile int	g_end = 0;

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
		usleep (250);
	i++;
	}
	return ;
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

void	handle_sigusr(int signal, siginfo_t *si, void *data)
{
	(void) data;
	(void) si;
	if (signal == SIGUSR1)
		g_end = 1;
}

void	ft_sendpid(int pid)
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
	usleep(50);
	ft_sendend(pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	s1;
	t_struct			client;

	client.i = -1;
	ft_memset(&s1, 0, sizeof(s1));
	s1.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &s1, NULL);
	client.pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][++client.i])
		{
			client.binary = ft_dtob(argv[2][client.i]);
			client.binary_str = ft_itoa_client(client.binary);
			signal_send(client.binary_str, client.pid);
		}
		ft_sendend(client.pid);
		ft_sendpid(client.pid);
		if (g_end == 1)
			ft_putstr_fd("📬✔️✔️", 1);
	}
	else
		ft_printf("Error try: client [the server PID] [The string to send]");
	return (0);
}
