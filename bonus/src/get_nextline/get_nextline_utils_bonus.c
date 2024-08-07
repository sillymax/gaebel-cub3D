/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextline_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:07:33 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:28:28 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	contains_newline(char *remaining_line)
{
	return (ft_strchr(remaining_line, '\n'));
}

int	read_and_check(int fd, char *buffer, int buffer_size)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, buffer_size);
	if (bytes_read == -1)
	{
		printf("read failed for bytes_read\n");
		exit(-1);
	}
	return (bytes_read);
}
