/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:19:25 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:42:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rstrspn(const char *str, const char *accept)
{
	int	spanlen;
	int	len;

	if (!str || !accept)
		return (0);
	spanlen = 0;
	len = ft_strlen(str);
	while (len > 0 && ft_strchr(accept, str[len - 1]))
	{
		spanlen++;
		len--;
	}
	return (spanlen);
}
