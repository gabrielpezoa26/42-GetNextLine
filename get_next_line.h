/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:53 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/15 16:51:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
# include <sys/types.h>
# include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> //apagarrrrrr
char	*get_next_line(int fd);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);

#endif