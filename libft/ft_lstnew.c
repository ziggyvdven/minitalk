/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:55:05 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/09 16:00:47 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*next;

	next = (t_list *)malloc(sizeof(t_list));
	if (!(next))
		return (NULL);
	next->content = content;
	next->next = NULL;
	return (next);
}

// int main(void)
// {
//     char *str = "hello world";
//     t_list *node = ft_lstnew(str);
//     if (node == NULL)
//     {
//         printf("Error: failed to create new node\n");
//         return (1);
//     }
//     printf("Node content: %s\n", (char *)node->content);
//     return (0);
// }
