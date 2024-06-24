/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:36:38 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 18:18:11 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_str(const char *s1, const char *s2, int free_option)
{
	if (free_option == 1 || free_option == 3)
		free((void *)s1);
	if (free_option == 2 || free_option == 3)
		free((void *)s2);
}

// - free_option: Integer value:
// 0: Don't free any input strings.
// 1: Free s1 after concatenation.
// 2: Free s2 after concatenation.
// 3: Free both s1 and s2 after concatenation.
char	*ft_strjoin(const char *s1, const char *s2, int free_option)
{
	int		totallen;
	char	*result;

	if (!s1 && !s2 && (free_option < 0 || free_option > 3))
		return (NULL);
	totallen = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * totallen);
	if (!result)
	{
		free_str(s1, s2, free_option);
		return (NULL);
	}
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	free_str(s1, s2, free_option);
	return (result);
}
