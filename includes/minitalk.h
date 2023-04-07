/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:37:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/06 16:17:14 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include	"../libft/libft.h"
# include	<signal.h>
# include	<sys/types.h>
# include	<unistd.h>

typedef struct s_struct
{
	int			pid;
	int			binary;
	int			i;
	char		*binary_str;
}				t_struct;

char	*ft_itoa_client(int n);
int		ft_dtob(int nbr);
char	ft_btod(int num);
void	ft_printbyte(char *byte);
int		ft_checkend(char *byte);
void	signal_send(char *str, int pid);
void	ft_sendend(int pid);
int		ft_makepid(char *byte, int i);

#endif
