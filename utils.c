/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:02:19 by zvandeven         #+#    #+#             */
/*   Updated: 2023/03/24 12:17:00 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
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

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	temp;

	temp = n;
	len = ft_len(temp);
	ptr = (char *)ft_calloc(sizeof(char), (7 + 1));
	if (!(ptr))
		return (NULL);
	if (n == 0 || len == 6)
		ptr[0] = '0';
	if (len == 7)
	len--;
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

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		nb;
	char	*str;

	sign = 1;
	nb = 0;
	i = 0;
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
	nb *= sign;
	return (nb);
}