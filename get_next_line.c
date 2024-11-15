/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/15 18:36:00 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *y)
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

static char	*read_line(char **potato)
{
	int		index;
	char	*xuxu;
	char	*leftover;

	if (*potato == NULL || **potato == '\0')
		return (NULL);
	index = 0;
	while ((*potato)[index] != '\0' && (*potato)[index] != '\n')
		index++;
	if ((*potato)[index] == '\n')
		xuxu = malloc(sizeof(char) * (index + 2));
	else
		xuxu = malloc(sizeof(char) * (index + 1));
	if (xuxu == NULL)
		return (NULL);
	ft_strlcpy(xuxu, *potato, index + 2);
	if ((*potato)[index] == '\n')
		leftover = ft_strdup(&(*potato)[index + 1]);
	else
		leftover = NULL;
	free(*potato);
	*potato = leftover;
	return (xuxu);
}

char	*get_next_line(int fd)
{
	static char	*potato;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	potato = read_file(fd, potato);
}
