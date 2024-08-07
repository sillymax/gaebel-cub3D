/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:58:29 by ychng             #+#    #+#             */
/*   Updated: 2024/08/06 10:36:21 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int num)
{
	int	len;

	if (num == 0)
	{
		len = 1;
		return (len);
	}
	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*generate_str(int num, int len)
{
	char	*str;
	bool	isnegative;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	isnegative = false;
	if (num < 0)
	{
		isnegative = true;
		num = -num;
	}
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	if (isnegative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*result;

	len = get_len(num);
	result = generate_str(num, len);
	return (result);
}
