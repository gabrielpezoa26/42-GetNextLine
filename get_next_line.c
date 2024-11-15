/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/15 16:59:09 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_file(int fd, char *y)
{
	ssize_t	bytes_read;
	char	*temp;
	
	if (y == NULL)
		y = ft_calloc(1, 1);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		temp[bytes_read] = '\0';
		y = ft_strjoin(y, temp);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			return (NULL);
	}
	return (y);
}
char *get_next_line(int fd)
{
	static char *remember;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	remember = read_file(fd, remember);
}
