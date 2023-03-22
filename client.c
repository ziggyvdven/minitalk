/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:54:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/22 19:30:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/minitalk.h"

int	ft_dtob(int nbr)
{
	int		binary_num;
	int		bit_position;
	int		bit;

	bit_position = 1;
	binary_num = 0;
	while (nbr > 0)
	{
		bit = nbr % 2;
		binary_num += bit * bit_position;
		nbr /= 2;
		bit_position *= 10;
	}
	return (binary_num);
}

void	signal_send(char *str, int pid)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
		{
			kill (pid, SIGUSR1);
			usleep(500000);
		}
		if (str[i] == '1')
		{
			kill (pid, SIGUSR2);
			usleep(500000);
		}
	i++;
	}
}

int main(int argc, char **argv)
{
	int		pid;
	int		binary;
	int		i;
	char	*binary_str;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
	// function that converts an char to a binary 
		while (argv[2][i])
		{
			binary = ft_dtob(argv[2][i]);
			binary_str = ft_itoa(binary);
			ft_printf("\nchar = %s\n", binary_str);
			signal_send(binary_str, pid);
			i++;
			sleep(2);
		}
	}
	return (0);
}
