/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:06:09 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/10 11:43:16 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (!((unsigned char)str1[i] == (unsigned char)str2[i]))
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char s[] = "sayut";
// 	char b[] = "salut";
// 	printf("%d", ft_memcmp(s, b, 6));
// 	return (0);
// }