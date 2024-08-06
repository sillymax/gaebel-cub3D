/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:35:06 by ychng             #+#    #+#             */
/*   Updated: 2024/08/06 10:36:34 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	process_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '-')
	{
		sign = -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	return (sign);
}

static int	process_intpart(const char **nptr)
{
	int	result;

	result = 0;
	while (ft_isdigit(**nptr))
	{
		result = result * 10 + (**nptr - '0');
		(*nptr)++;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	if (!nptr)
		return (0);
	while (ft_isblank(*nptr))
		nptr++;
	if (*nptr == '\0')
		return (0);
	sign = process_sign(&nptr);
	result = process_intpart(&nptr);
	return (result * sign);
}
