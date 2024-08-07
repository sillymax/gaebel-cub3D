/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:25:09 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:53:00 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcspn(const char *str, const char *reject)
{
	int	spanlen;

	if (!str || !reject)
		return (0);
	spanlen = 0;
	while (str[spanlen] && !ft_strchr(reject, str[spanlen]))
		spanlen++;
	return (spanlen);
}
