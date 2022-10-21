/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:58:50 by busmanov          #+#    #+#             */
/*   Updated: 2022/10/21 11:34:10 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//locate the line that should be read in our fd
char	*ft_read_line(char *buffer, int fd, int size_l)
{
	char	*temp;
	int		byte_count;//number of bytes read

	byte_count = 1;
	temp = (char *)malloc(sizeof(char) * (size_l + 1));
	if (temp == NULL)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && byte_count != 0)//while looking for a \n,
	{//check the bytes read, if no error has occured, save the amount of bytes read
		byte_count = read(fd, temp, size_l);//reading from fd into temp up to BUFFER_SIZE
		if (byte_count == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[byte_count] = '\0';//add a null terminator at the last position stored in our fd
		buffer = ft_strjoin(buffer, temp);//concatenate two strings
	}
	free(temp);
	return (buffer);//return the concatenated string
}
//return the line being read
char	*ft_ret_read_line(char *buffer)
{
	char	*line;
	int		x;

	x = 0;
	if (!buffer[x])
		return (NULL);
	while (buffer[x] != '\n' && buffer[x])//search for the \n or \0
		x++;
	line = malloc(sizeof(char) * (x + 2));//allocate enough momory in my new string
	if (!line)
		return (NULL);
	x = 0;
	while (buffer[x] != '\n' && buffer[x]) //copy char by char from source to new string "line"
	{
		line[x] = buffer[x];
		x++;
	}
	if (buffer[x] == '\n') //in case i copied until \n, i gotta add it to the new string too
	{
		line[x] = '\n';
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_update_line(char *buffer)//save all the content that has not yet been read
{       //update my buffer
	int		x;
	int		y;
	char	*new_str;

	x = 0;
	y = -1;
	while (buffer[x] != '\n' && buffer[x])
		x++;//now we know how many chars there are until the first \n
	if (!buffer[x])
	{
		free(buffer);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (ft_strlen(buffer) - x + 1));//allocate enough memory for my new string
	if (!new_str) //check if its allocated successfully
		return (NULL);
	x++;
	while (buffer[x])
	{//++y: first incrementing, then assigning below
		new_str[++y] = buffer[x];
		x++;
	}
	new_str[++y] = '\0';
	free(buffer);
	return (new_str);
}
//reads from fd and returns one line or NULL
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			size_l;

	size_l = BUFFER_SIZE;
	if (fd < 0 || size_l <= 0)
		return (NULL);
	buffer = ft_read_line(buffer, fd, size_l);//read our line for the \n or any error
	if (buffer == NULL)
		return (NULL);
	line = ft_ret_read_line(buffer);//return the line that was read
	buffer = ft_update_line(buffer);//save all the content that has not yet been read from the fd
	return (line);
}
