/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:16:16 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 20:47:02 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handledigit(t_resultinfo *info, long long num)
{
	int		base;
	char	decimal[11];

	base = 10;
	ft_strcpy(decimal, "0123456789");
	if (num < 0)
	{
		num = -num;
		write_tobuffer(info, '-');
	}
	if (num >= base)
		handledigit(info, num / base);
	write_tobuffer(info, decimal[num % base]);
}

void	handlepointer(t_resultinfo *info, uintptr_t ptr)
{
	uintptr_t	base;
	char		hexadecimal[17];

	base = 16;
	ft_strcpy(hexadecimal, "0123456789abcdef");
	if (ptr >= base)
		handlepointer(info, ptr / base);
	else
	{
		write_tobuffer(info, '0');
		write_tobuffer(info, 'x');
	}
	write_tobuffer(info, hexadecimal[ptr % base]);
}

void	handlelowhex(t_resultinfo *info, unsigned int num)
{
	unsigned int	base;
	char			decimal[17];

	base = 16;
	ft_strcpy(decimal, "0123456789abcdef");
	if (num >= base)
		handledigit(info, num / base);
	write_tobuffer(info, decimal[num % base]);
}

void	handleupphex(t_resultinfo *info, unsigned int num)
{
	unsigned int	base;
	char			decimal[17];

	base = 16;
	ft_strcpy(decimal, "0123456789ABCDEF");
	if (num >= base)
		handledigit(info, num / base);
	write_tobuffer(info, decimal[num % base]);
}
