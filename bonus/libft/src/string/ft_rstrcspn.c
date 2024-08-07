/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrcspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:48:49 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:42:07 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rstrcspn(const char *str, const char *reject)
{
	int	spanlen;
	int	len;

	if (!str || !reject)
		return (0);
	spanlen = 0;
	len = ft_strlen(str);
	while (len > 0 && !ft_strchr(reject, str[len - 1]))
	{
		spanlen++;
		len--;
	}
	return (spanlen);
}
