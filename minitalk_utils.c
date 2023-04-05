/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:40:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/05 15:13:13 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	ft_len_client(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_client(int n)
{
	char		*ptr;
	int			len;
	long int	temp;

	temp = n;
	ptr = (char *)ft_calloc(sizeof(char), (8 + 1));
	if (!(ptr))
		return (NULL);
	if (ft_len_client(temp) == 6 || ft_len_client(temp) == 7)
		ptr[0] = '0';
	if (ft_len_client(temp) == 6)
		ptr[1] = '0';
	len = 7;
	while (temp != 0)
	{
		if (temp < 0)
		{
			ptr[0] = '-';
			temp *= -1;
		}
		ptr[len] = temp % 10 + 48;
		temp /= 10;
		len--;
	}		
	return (ptr);
}

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
