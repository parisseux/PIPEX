/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:47:52 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/10 13:18:00 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;
	int		len;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = j + i;
	s3 = (char *)malloc((i + j + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	k = 0;
	while (k < i)
	{
		s3[k] = s1[k];
		k++;
	}
	j = 0;
	while (k < len)
		s3[k++] = s2[j++];
	s3[k] = '\0';
	return (s3);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *strs = "salut";
// 	char *sep = "❤️";
// 	printf("%s\n", ft_strjoin(strs, sep));
// 	return (0);
// }