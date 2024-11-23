/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/23 15:08:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clear_backup(char *old_backup)
{
	free(old_backup);
	return (NULL);
}

static char	*read_and_store(int fd, char *buffer, char *stored)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	if (stored == NULL)
	{
		stored = ft_strdup("");
		if (stored == NULL)
			return (NULL);
	}
	while (ft_strchr(stored, '\n') == NULL && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (clear_backup(stored));
		buffer[bytes] = '\0';
		temp = stored;
		stored = ft_strjoin(temp, buffer);
		free(temp);
		if (stored == NULL)
			return (NULL);
	}
	return (stored);
}

static char	*extract_line(char *stored)
{
	int		index;
	char	*line;

	index = 0;
	if (stored[index] == '\0')
		return (NULL);
	while (stored[index] != '\0' && stored[index] != '\n')
		index++;
	line = ft_substr(stored, 0, index + 1);
	return (line);
}

static char	*update_backup(char *stored)
{
	int		index;
	char	*new_backup;

	index = 0;
	while (stored[index] != '\0' && stored[index] != '\n')
		index++;
	if (stored[index] == '\0')
		return (clear_backup(stored));
	new_backup = ft_substr(stored, index + 1, ft_strlen(stored) - index);
	free(stored);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stored;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	stored = read_and_store(fd, buffer, stored);
	free(buffer);
	if (stored == NULL)
		return (NULL);
	line = extract_line(stored);
	stored = update_backup(stored);
	return (line);
}
