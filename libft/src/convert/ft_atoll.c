/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:52:27 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 19:17:46 by ychng            ###   ########.fr       */
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
	else
		(*nptr)++;
	return (sign);
}

static long long	process_longlongpart(const char **nptr)
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

long long	ft_atoll(const char *nptr)
{
	int			sign;
	long long	result;

	if (!nptr)
		return (0);
	while (ft_isblank(*nptr))
		nptr++;
	if (*nptr == '\0')
		return (0);
	sign = process_sign(&nptr);
	result = process_longlongpart(&nptr);
	return (result * sign);
}
