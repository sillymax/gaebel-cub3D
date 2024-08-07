/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:40:16 by ychng             #+#    #+#             */
/*   Updated: 2024/08/06 10:35:32 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initinfo(t_resultinfo *info, char *buffer, size_t size)
{
	info->buffer = buffer;
	info->size = size;
}

static void	processformat(t_resultinfo *info, const char *format, va_list args)
{
	int	pos;

	pos = 0;
	while (format[pos])
	{
		if (format[pos] == '%' && isspecifier(format[pos + 1]))
		{
			pos++;
			handlespecifier(info, format, args, &pos);
		}
		else
			write_tobuffer(info, format[pos]);
		pos++;
	}
	*(info->buffer) = '\0';
}

int	ft_snprintf(char *buffer, size_t size, const char *format, ...)
{
	va_list			args;
	t_resultinfo	info;

	va_start(args, format);
	initinfo(&info, buffer, size);
	processformat(&info, format, args);
	va_end(args);
	return ((int)(size - info.size));
}

// int main()
// {
// 	char	buffer[100];
// 	int		x;

// 	x = +2147483648;
// 	printf("%d\n", ft_snprintf(buffer, 100, "%s\n", NULL));
// 	printf("%d\n", printf("%s", buffer));
// 	// printf("real hi there %u%%%s\n", 22222147483649);
// }