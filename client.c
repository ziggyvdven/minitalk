/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:54:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/04 17:43:18 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"

int		g_rec = 0;

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
		usleep (400);
		// pause ();
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
		g_rec = 1;
	else
		return ;
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
	ft_sendend(pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	s1;
	int					pid;
	int					binary;
	int					i;
	char				*binary_str;

	i = 0;
	ft_memset(&s1, 0, sizeof(s1));
	s1.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s1, NULL);
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][i])
		{
			binary = ft_dtob(argv[2][i]);
			binary_str = ft_itoa_client(binary);
			signal_send(binary_str, pid);
			i++;
		}
		ft_sendend(pid);
		ft_sendpid(pid);
		if (g_rec == 1)
		{
			printf("message recieved\n");
			return (0);
		}
	}
	else
		printf("Error try: client [the server PID] [The string to send]");
	return (0);
}
