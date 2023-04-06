/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:20:52 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/05 18:05:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<string.h>
# include	<stdarg.h>
# include	<stdio.h>
# include	<unistd.h>
# include   "../../libft.h"

int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_putnbr_pf(int n, int count);
int		ft_putstr(char *str);
int		ft_putunsing(unsigned int n, int count);
int		ft_putnbr_base_pf(unsigned int nbr, int count, int b);
int		ft_printadr(va_list *args);

#endif