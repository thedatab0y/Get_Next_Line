/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:11:41 by busmanov          #+#    #+#             */
/*   Updated: 2022/10/21 10:18:59 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(char *buffer, int fd)
{
	char	*temp;
	int		byte_count;

	byte_count = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && byte_count != 0)
	{
		byte_count = read(fd, temp, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[byte_count] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*ft_ret_read_line(char *buffer)
{
	char	*line;
	int		x;

	x = 0;
	if (!buffer[x])
		return (NULL);
	while (buffer[x] != '\n' && buffer[x])
		x++;
	line = malloc(sizeof(char) * (x + 2));
	if (!line)
		return (NULL);
	x = 0;
	while (buffer[x] != '\n' && buffer[x])
	{
		line[x] = buffer[x];
		x++;
	}
	if (buffer[x] == '\n')
	{
		line[x] = '\n';
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_update_line(char *buffer)
{
	int		x;
	int		y;
	char	*new_str;

	x = 0;
	y = -1;
	while (buffer[x] != '\n' && buffer[x])
		x++;
	if (!buffer[x])
	{
		free(buffer);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (ft_strlen(buffer) - x + 1));
	if (!new_str)
		return (NULL);
	x++;
	while (buffer[x])
	{
		new_str[++y] = buffer[x];
		x++;
	}
	new_str[++y] = '\0';
	free(buffer);
	return (new_str);
}

char	*get_next_line(int fd)
{ //make the static variable an array of strings, each corresponding to one file descriptor.
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_line(buffer[fd], fd, BUFFER_SIZE);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_ret_read_line(buffer[fd]);
	buffer[fd] = ft_update_line(buffer[fd]);
	return (line);
}
