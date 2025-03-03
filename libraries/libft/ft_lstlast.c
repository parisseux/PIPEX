/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:35:09 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/09 15:43:24 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main(void)
// {
//     t_list node1, node2, node3;

//     node1.content = "Node 1";
//     node2.content = "Node 2";
//     node3.content = "Node 3";
//     node1.next = &node2;
//     node2.next = &node3;
//     node3.next = NULL;
//     t_list *last_node = ft_lstlast(&node1);
//     printf("%s", (char *)last_node->content);
//     return 0;
// }