/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:05:37 by busmanov          #+#    #+#             */
/*   Updated: 2022/10/21 09:19:19 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *temp, char *buffer)
{
	char	*str;
	int		x;
	int		y;

	if (!temp)
	{
		temp = malloc(1);
		temp[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(temp) + ft_strlen(buffer) + 1)));
	if (!str)
		return (NULL);
	x = -1;
	y = 0;
	if (temp)
	{
		while (temp[++x] != '\0')
			str[x] = temp[x];
	}
	while (buffer[y] != '\0')
		str[x++] = buffer[y++];
	str[ft_strlen(temp) + ft_strlen(buffer)] = '\0';
	free(temp);
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	int	x;

	x = 0;
	if (!str)
		return (NULL);
	while (str[x] != 0)
	{
		if (str[x] == (char)c)
			return ((char *)&str[x]);
		x++;
	}
	if (str[x] == (char)c)
		return ((char *)&str[x]);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}
