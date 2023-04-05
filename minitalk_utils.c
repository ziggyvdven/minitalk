/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:40:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/04 12:18:04 by zvandeven        ###   ########.fr       */
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


int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		nb;
	char	*str;

	sign = 1;
	nb = 0;
	i = 0;
	if (!nptr)
		return (0);
	str = (char *)nptr;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!s)
		return ;
	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = b;
	if (!b)
		return (NULL);
	while (i < len)
	{
		*ptr = c;
		ptr++;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	if (nmemb >= SIZE_MAX || size >= SIZE_MAX)
		return (0);
	ptr = (char *)malloc(nmemb * size);
	if (!(ptr))
		return (NULL);
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_len(long int n)
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

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	temp;

	temp = n;
	len = ft_len(temp);
	ptr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!(ptr))
		return (NULL);
	ptr[len--] = '\0';
	if (n == 0)
	ptr[0] = '0';
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

