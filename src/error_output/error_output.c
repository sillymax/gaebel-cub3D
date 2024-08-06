/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:59:58 by ychng             #+#    #+#             */
/*   Updated: 2024/08/06 10:23:32 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	exit_with_error(char *msg)
{
	int	fd;

	fd = 2;
	ft_putstr_fd("Error\n", fd);
	ft_putstr_fd("msg: ", fd);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	exit(1);
}

bool	return_with_error(char *msg)
{
	int	fd;

	fd = 2;
	ft_putstr_fd("Error\n", fd);
	ft_putstr_fd("msg: ", fd);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	return (FAIL);
}
