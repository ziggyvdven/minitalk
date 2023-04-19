/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:58:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/19 16:11:07 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin_char(char *s1, char s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	j = 0;
	i = (ft_strlen(s1) + 1);
	if (!s1 || !s2)
		return (0);
	ptr = (char *)ft_calloc(sizeof(char), i + 1);
	if (!(ptr))
		return (NULL);
	i = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	ptr[j++] = s2;
	ptr[j] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}

// int main()
// {
// 	char str[] = "hey";
// 	char a	   = 'h';

// 	ft_printf("%s\n", str);
// 	ft_printf("%s\n", ft_strjoin_char(str, a));
// }
