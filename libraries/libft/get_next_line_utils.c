/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:41:49 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/06 15:13:16 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_gnl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *temp, char *buff)
{
	char	*s;

	if (!temp)
	{
		temp = (char *)malloc(1);
		if (!temp)
			return (NULL);
		temp[0] = '\0';
	}
	if (!buff)
		return (NULL);
	s = (char *)malloc((ft_strlen_gnl(temp)
				+ ft_strlen_gnl(buff) + 1) * sizeof(char));
	if (!s)
	{
		free(temp);
		return (NULL);
	}
	s = ft_strjoin2_gnl(s, temp, buff);
	return (s);
}

char	*ft_strjoin2_gnl(char *s, char *temp, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i])
	{
		s[i] = temp[i];
		i++;
	}
	while (buff[j])
		s[i++] = buff[j++];
	s[i] = '\0';
	free(temp);
	return (s);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
