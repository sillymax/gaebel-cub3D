/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 06:49:03 by ychng             #+#    #+#             */
/*   Updated: 2024/04/21 07:43:21 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	process_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '-')
	{
		(*nptr)++;
		sign = -1;
	}
	else if (**nptr == '+')
		(*nptr)++;
	return (sign);
}

static double	process_intpart(const char **nptr)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**nptr))
	{
		result = result * 10.0 + (**nptr - '0');
		(*nptr)++;
	}
	return (result);
}

static double	process_fractionpart(const char **nptr)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (**nptr == '.')
	{
		(*nptr)++;
		while (ft_isdigit(**nptr))
		{
			fraction = fraction * 10.0 + (**nptr - '0');
			divisor *= 10.0;
			(*nptr)++;
		}
	}
	return (fraction / divisor);
}

static void	process_exponentpart(const char **nptr, int	*expsign, int *expval)
{
	*expsign = 1;
	*expval = 0;
	if (**nptr == 'e' || **nptr == 'E')
	{
		(*nptr)++;
		if (**nptr == '-')
		{
			*expsign = -1;
			(*nptr)++;
		}
		else if (**nptr == '+')
			(*nptr)++;
		while (ft_isdigit(**nptr))
		{
			*expval = *expval * 10 + (**nptr - '0');
			(*nptr)++;
		}
	}
}

double	ft_atof(const char *nptr)
{
	int		sign;
	double	result;
	double	fraction;
	int		expsign;
	int		expval;

	if (!nptr)
		return (0.0);
	while (ft_isblank(*nptr))
		nptr++;
	if (*nptr == '\0')
		return (0.0);
	sign = process_sign(&nptr);
	result = process_intpart(&nptr);
	fraction = process_fractionpart(&nptr);
	process_exponentpart(&nptr, &expsign, &expval);
	result += fraction;
	if (expsign == -1)
		result = result / ft_pow(10, expval);
	else
		result = result * ft_pow(10, expval);
	return (result * sign);
}
