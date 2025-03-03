/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:39:56 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/04 15:16:23 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_trash(char *temp)
{
	char	*trash;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
	{
		free(temp);
		return (NULL);
	}
	trash = (char *)malloc(sizeof(char) * (ft_strlen_gnl(temp) - i + 1));
	if (!trash)
	{
		free(temp);
		return (NULL);
	}
	i++;
	while (temp[i])
		trash[j++] = temp[i++];
	trash[j] = '\0';
	free(temp);
	return (trash);
}

char	*fill_use_buffer(int fd, char *temp, int i, char *buffer)
{
	while (1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		if (i == 0)
			break ;
		buffer[i] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr_gnl(temp))
			break ;
	}
	free(buffer);
	return (temp);
}

char	*get_newline(char *temp)
{
	char	*new_line;
	int		j;
	int		i;

	i = 0;
	if (temp[i] == '\0')
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		new_line = (char *)malloc(sizeof(char) * (i + 2));
	else
		new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_line[j] = temp[j];
		j++;
	}
	if (temp[i] == '\n')
		new_line[j++] = '\n';
	new_line[j] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*temp;
	int			i;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	temp = fill_use_buffer(fd, temp, i, buffer);
	if (!temp)
		return (NULL);
	new_line = get_newline(temp);
	temp = get_trash(temp);
	if (!new_line)
	{
		free(temp);
		return (NULL);
	}
	return (new_line);
}
