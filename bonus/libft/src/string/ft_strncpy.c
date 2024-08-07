/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:41:34 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 18:20:53 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies at most 'n' characters from 'src' to 'dest',
// ensuring 'dest' is null-terminated up to 'n' characters.
// Does not terminate 'dest' if 'src' is shorter than 'n'.
char	*ft_strncpy(char *dest, const char *src, int n)
{
	char	*start;

	if (!dest || !src || n < 0)
		return (dest);
	start = dest;
	while (*src && n--)
		*dest++ = *src++;
	while (n-- > 0)
		*dest++ = '\0';
	return (start);
}
