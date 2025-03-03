/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:49:53 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/04 10:41:38 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s = "salut";
// 	char *result = (char *)ft_memchr(s, 'l', 4);

// 	if (result != NULL)
// 		printf("Character found: %s\n", result);
// 	else
// 		printf("Character not found in the first 4 bytes\n");

// 	return 0;
// }