/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:58:53 by busmanov          #+#    #+#             */
/*   Updated: 2022/10/21 11:02:07 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//allocates and returns a new string that is the concatenation of two strings.
char	*ft_strjoin(char *temp, char *buffer)
{//returns a char pointer to new string if success, otherwise a NULL if there is nothing to read or error.
	char	*str;
	int		x;
	int		y;

	if (!temp) //temp is prefix
	{
		temp = malloc(1);
		temp[0] = '\0';
	}//allocate memory for new string str
	str = malloc(sizeof(char) * ((ft_strlen(temp) + ft_strlen(buffer) + 1))); // buffer is suffix
	if (!str)//check if the memory is allocated correctly
		return (NULL);
	x = -1;
	y = 0;
	if (temp)
	{//++x: first incremenent then assign
		while (temp[++x] != '\0')
			str[x] = temp[x];
	}
	while (buffer[y] != '\0')
		str[x++] = buffer[y++];//x++: first assign, then increment
	str[ft_strlen(temp) + ft_strlen(buffer)] = '\0';
	free(temp);
	return (str);
}
//searches for the first occurence of the string in string str where c is the character to be checked
char	*ft_strchr(char *str, int c)
{
	int	x;
//The function strchr() returns a pointer to the located 
	x = 0;//character, or NULL if the character does not appear in the string.
	if (!str)
		return (NULL);
	while (str[x] != 0)
	{
		if (str[x] == (char)c)//typecasting c
			return ((char *)&str[x]); //returns a pointer to the located char
		x++;
	}
	if (str[x] == (char)c)
		return ((char *)&str[x]);
	return (0);
}
//returns the length of the string where str is the string whose length is yet to be found.
size_t	ft_strlen(char *str)//finds the length of the string str up to, yet not including the null terminating character.
{ //size_t improves portability,efficiency
	size_t	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}
//The function strchr() returns a pointer to the located 
//character, or NULL if the character does not appear in the string.