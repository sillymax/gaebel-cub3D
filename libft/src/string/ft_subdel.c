/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:09:46 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 20:19:19 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_subdel(const char *str, int start, int len)
{
	int		strlen;
	char	*result;

	if (!str || start < 0 || len < 0)
		return (NULL);
	strlen = ft_strlen(str);
	if (start >= strlen)
		return (NULL);
	result = malloc(sizeof(char) * (strlen - len + 1));
	if (!result)
		return (NULL);
	ft_strncpy(result, str, start);
	ft_strcpy(result + start, str + start + len);
	return (result);
}
