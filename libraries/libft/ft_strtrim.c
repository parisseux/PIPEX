/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:07:21 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/10 14:46:52 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static int	ft_find_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	return (end);
}

char	*ft_fill_new(char *new, char const *s1, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	if (start > end)
	{
		new = (char *)malloc(1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	new = (char *)malloc((end - start + 2) * sizeof(char));
	if (!new)
		return (NULL);
	return (ft_fill_new(new, s1, start, end));
}

// #include <stdio.h>
// int main(void)
// {
// 	char s1[] = "akakasalutakakaka";
// 	char s2[] = "ak";
// 	char *str = ft_strtrim(s1, s2);
// 	printf("%s", str);
// 	free(str);
// 	return (0);
// }