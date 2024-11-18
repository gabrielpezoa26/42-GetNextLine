/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/18 15:06:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static char	*fill_buffer(int fd, char *y)
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
			return (y);
	}
	return (y);
}

static char	*line_extractor(char **buffer)
{
	int		index;
	char	*xuxu;
	char	*leftover;

	if (*buffer == NULL || **buffer == '\0')
		return (NULL);
	index = 0;
	while ((*buffer)[index] != '\0' && (*buffer)[index] != '\n')
		index++;
	if ((*buffer)[index] == '\n')
		xuxu = malloc(sizeof(char) * (index + 2));
	else
		xuxu = malloc(sizeof(char) * (index + 1));
	if (xuxu == NULL)
		return (NULL);
	ft_strlcpy(xuxu, *buffer, index + 2);
	if ((*buffer)[index] == '\n')
		leftover = ft_strdup(&(*buffer)[index + 1]);
	else
		leftover = NULL;
	free(*buffer);
	*buffer = leftover;
	return (xuxu);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fill_buffer(fd, buffer);
	return (line_extractor(&buffer));
}
