/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:22:22 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/09 15:17:25 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	print_strlen(void *content)
// {
// 	size_t len = ft_strlen(content);
// 	printf("length of '%s' : %zu\n", (char *)content, len);
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// int main(void)
// {

//     t_list node1, node2, node3;

//     node1.content = "Node 1";
//     node2.content = "Node 2";
//     node3.content = "Node 3";
//     node1.next = &node2;
//     node2.next = &node3;
//     node3.next = NULL;  // The last node points to NULL
//     ft_lstiter(&node1, print_strlen);
//     return 0;
// }