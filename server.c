/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:18:23 by zvan-de-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/05 13:01:18 by zvan-de-         ###   ########.fr       */
=======
/*   Updated: 2023/04/04 17:36:03 by zvandeven        ###   ########.fr       */
>>>>>>> 3952d70a7fca5556d54d32285b9a655d9d624b03
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"

volatile char	g_bit;
int		g_pid;

void	handle_sigusr(int signal, siginfo_t *si, void *data)
{
	(void)data;
	g_pid = si->si_pid;
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

int	ft_printbyte(char *byte)
{
	int				i;

	byte[8] = '\0';
	if (ft_checkend(byte))
	{
		printf("\n");
<<<<<<< HEAD
		return ;
	}
	i = ft_atoi(byte);
	i = ft_btod(i);
	ft_printf("%c", i);
=======
		end = 1;
		return (0);
	}
	i = ft_atoi(byte);
	i = ft_btod(i);
	if (end == 1)
	{
		if (ft_checkend(byte))
		{
			pid[pos] = '\0';
			kill (ft_atoi(pid), SIGUSR1);
			ft_bzero(pid, 6);
			pos = 0;
			end = 0;
			return (0);
		}
		pid[pos++] = i;
	}
	else
		printf("%c", i);
	return(0);
>>>>>>> 3952d70a7fca5556d54d32285b9a655d9d624b03
}

int	main(void)
{
	struct sigaction	s1;
	char				*byte;
	int					i;
	sigset_t			set;

	i = 0;
	byte = NULL;
	ft_memset(&s1, 0, sizeof(s1));
	s1.sa_sigaction = handle_sigusr;
	s1.sa_flags = SA_SIGINFO;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	s1.sa_mask = set;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s1, NULL);
	printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		pause ();
		if (byte == NULL)
			byte = (char *)malloc(sizeof(char) * 8 + 1);
		byte[i] = g_bit;
<<<<<<< HEAD
		if (i == 8)
=======
		if (++i == 8)
>>>>>>> 3952d70a7fca5556d54d32285b9a655d9d624b03
		{
			i = ft_printbyte(byte);
			free(byte);
			byte = NULL;
		}
<<<<<<< HEAD
		i++;
	}
=======
		// kill (g_pid, SIGUSR2);	
	} 
>>>>>>> 3952d70a7fca5556d54d32285b9a655d9d624b03
	return (0);
}
