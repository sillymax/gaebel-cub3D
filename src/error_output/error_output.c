/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:59:58 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 06:22:09 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	exit_with_error(char *msg)
{
	int	fd;

	fd = 2;
	ft_putstr_fd("error: ", fd);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	exit(FAIL);
}

bool	return_with_error(char *msg)
{
	int	fd;

	fd = 2;
	ft_putstr_fd("error: ", fd);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);

	return (FAIL);
}
