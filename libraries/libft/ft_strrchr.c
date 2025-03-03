/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:59:06 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/04 10:42:19 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const	char*s, int c)
{
	char	z;
	int		i;

	z = (char)c;
	i = 0;
	while (s[i])
		i++;
	if (z == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == z)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
