/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:53 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/12 15:39:46 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define FT_PRINTF_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> //apagarrrrrr
char	*get_next_line(int fd);