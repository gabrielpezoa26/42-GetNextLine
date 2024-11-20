/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/20 19:19:05 by gabriel          ###   ########.fr       */
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

static char	*read_and_join(int fd, char *buffer, char *temp)
{
	ssize_t	bytes_read;
	char	*new_buffer;

	bytes_read = read(fd, temp, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		temp[bytes_read] = '\0';
		new_buffer = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = new_buffer;
		bytes_read = read(fd, temp, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

static char	*fill_buffer(int fd, char *buffer)
{
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_calloc(1, 1);
	buffer = read_and_join(fd, buffer, temp);
	free(temp);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

static char	*line_extractor(char **buffer)
{
	int		index;
	char	*line;
	char	*leftover;

	if (*buffer == NULL || **buffer == '\0')
		return (NULL);
	index = 0;
	while ((*buffer)[index] != '\0' && (*buffer)[index] != '\n')
		index++;
	if ((*buffer)[index] == '\n')
		line = malloc(sizeof(char) * (index + 2));
	else
		line = malloc(sizeof(char) * (index + 1));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, *buffer, index + 2);
	if ((*buffer)[index] == '\n')
		leftover = ft_strdup(&(*buffer)[index + 1]);
	else
		leftover = NULL;
	free(*buffer);
	*buffer = leftover;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fill_buffer(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = line_extractor(&buffer);
	return (line);
}
