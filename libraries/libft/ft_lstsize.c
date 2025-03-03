/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:27:19 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/09 13:34:44 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			count;
	t_list		*l;

	count = 0;
	l = lst;
	while (l != NULL)
	{
		count++;
		l = l -> next;
	}
	return (count);
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
//     printf("%d", ft_lstsize(&node1));
//     return 0;
// }