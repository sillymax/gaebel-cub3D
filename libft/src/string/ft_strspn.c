/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:33:57 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 18:23:24 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strspn(const char *str, const char *accept)
{
	int	spanlen;

	if (!str || !accept)
		return (0);
	spanlen = 0;
	while (str[spanlen] && ft_strchr(accept, str[spanlen]))
		spanlen++;
	return (spanlen);
}
