/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:51 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/20 18:25:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	*ft_memset(void	*s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*x;

	i = 0;
	x = (unsigned char *)s;
	while (i < n)
	{
		x[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*malloc_result;
	size_t	malloc_size;

	if (nmemb != 0 && size != 0 && nmemb > (size_t) -1 / size)
		return (NULL);
	malloc_size = nmemb * size;
	malloc_result = malloc(malloc_size);
	if (malloc_result == NULL)
		return (NULL);
	ft_memset(malloc_result, 0, malloc_size);
	return (malloc_result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	size_t	i;
	char	*dest_ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest_ptr = malloc(size);
	if (dest_ptr == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		dest_ptr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		dest_ptr[i] = *s2;
		i++;
		s2++;
	}
	dest_ptr[i] = '\0';
	return (dest_ptr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if ((dest == NULL) || (s == NULL))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
