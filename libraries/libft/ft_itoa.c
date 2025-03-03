/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:52:23 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/06 15:11:45 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	sign;
	int	count;

	count = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count + sign);
}

static char	*ft_fill_str(unsigned int num, char *number, int i, int len_number)
{
	i = len_number - 1;
	if (num == 0)
		number[i] = '0';
	else
	{
		while (num > 0)
		{
			number[i] = (num % 10) + '0';
			num = num / 10;
			i--;
		}
	}
	number[len_number] = '\0';
	return (number);
}

char	*ft_itoa(int n)
{
	char			*number;
	int				i;
	int				len_number;
	unsigned int	num;

	i = 0;
	len_number = ft_count(n);
	number = (char *)malloc((len_number + 1) * sizeof(char));
	if (!number)
		return (NULL);
	if (n < 0)
	{
		number[0] = '-';
		num = -n;
	}
	else
		num = n;
	number = ft_fill_str(num, number, i, len_number);
	return (number);
}
