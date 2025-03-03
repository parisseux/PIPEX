/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:49:52 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/10 11:10:18 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst1;
	const unsigned char	*src1;

	if (!src || !dst)
		return (NULL);
	src1 = (const unsigned char *)src;
	dst1 = (unsigned char *)dst;
	if (src1 >= dst1)
	{
		i = 0;
		while (i < n)
		{
			dst1[i] = src1[i];
			i++;
		}	
	}
	else
	{
		while (n-- > 0)
			dst1[n] = src1[n];
	}
	return (dst);
}

// #include <stdio.h>
// int main (void)
// {
//     char b[50] = "";
// 	char c[] = "";
//     ft_memmove(b,c,6);
//     printf("%s\n", b);
// 	printf("%s", memmove(b,c,6));
// }