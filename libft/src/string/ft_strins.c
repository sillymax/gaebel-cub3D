/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:08:25 by ychng             #+#    #+#             */
/*   Updated: 2024/04/30 00:38:31 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strins(const char *original, const char *insert, int pos)
{
	int		totallen;
	char	*result;

	if (!original || !insert || pos < 0)
		return (NULL);
	totallen = ft_strlen(original) + ft_strlen(insert) + 1;
	result = malloc(sizeof(char *) * totallen);
	if (!result)
		return (NULL);
	ft_strncpy(result, original, pos);
	result[pos] = '\0';
	ft_strcat(result, insert);
	ft_strcat(result, original + pos);
	return (result);
}
