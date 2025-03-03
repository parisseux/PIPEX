/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:29:55 by parissachat       #+#    #+#             */
/*   Updated: 2024/10/09 18:00:42 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_split {
	char	**tab;
	int		i;
	int		j;
	int		k;
}	t_split;

static int	ft_words_counts(char const *s, char c)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] != c && check == 0)
		{
			count++;
			check = 1;
		}
		else if (s[i] == c)
			check = 0;
		i++;
	}
	return (count);
}

static char	*ft_fill_table(char const *s, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static void	*ft_free(char **new, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free (new[i]);
		i++;
	}
	free (new);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	t_split	split;

	split.i = 0;
	split.j = 0;
	split.k = 0;
	split.tab = (char **)malloc(sizeof(char *) * (ft_words_counts(s, c) + 1));
	if (!split.tab || !s)
		return (NULL);
	while (split.i < ft_words_counts(s, c))
	{
		while (s[split.j] == c && s[split.j])
			split.j++;
		split.k = split.j;
		while (s[split.k] != c && s[split.k])
			split.k++;
		split.tab[split.i] = ft_fill_table(s, split.j, split.k);
		if (!split.tab[split.i])
			return (ft_free(split.tab, split.k));
		split.j = split.k;
		split.i++;
	}
	split.tab[split.i] = 0;
	return (split.tab);
}

// #include <stdio.h>
// int main(void)
// {
// 		int i = 0;
// 		char const *s = "salut comments";
// 		char c = 'a';
// 		char **table = ft_split(s, c);
// 		while (table[i])
// 		{
// 			printf("%s\n", table[i]);
// 			i++;
// 		}
// 		while (table[i])
// 		{
// 			free(table[i]);
// 			i++;
// 		}
// 		free(table);
// 		return (0);
// }
