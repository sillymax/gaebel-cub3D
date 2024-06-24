/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:17:59 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 20:29:26 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handlespecifier(t_resultinfo *info, const char *format, va_list args, \
						int *pos)
{
	if (format[*pos] == 'c')
		handlechar(info, va_arg(args, int));
	else if (format[*pos] == 's')
		handlestring(info, va_arg(args, char *));
	else if (format[*pos] == 'p')
		handlepointer(info, (uintptr_t)va_arg(args, void *));
	else if (format[*pos] == 'd' || format[*pos] == 'i')
		handledigit(info, va_arg(args, int));
	else if (format[*pos] == 'u')
		handledigit(info, va_arg(args, unsigned int));
	else if (format[*pos] == 'x')
		handlelowhex(info, va_arg(args, unsigned int));
	else if (format[*pos] == 'X')
		handleupphex(info, va_arg(args, unsigned int));
	else if (format[*pos] == '%')
		handlepercent(info);
}
