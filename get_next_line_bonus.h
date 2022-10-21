/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:52:20 by busmanov          #+#    #+#             */
/*   Updated: 2022/10/21 11:12:44 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef OPEN_MAX //if max number of open files allowed for a single program is not defined
#  define OPEN_MAX 256//define it as 256
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *temp, char *buffer);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_ret_read_line(char *buffer);
char	*ft_update_line(char *buffer);
char	*ft_read_line(char *buffer, int fd, int size_l);

#endif