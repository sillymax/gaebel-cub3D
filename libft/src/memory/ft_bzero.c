/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:26:12 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:27:28 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	ft_bzero(void *str, size_t size)
{
	unsigned char	*string;

	string = (unsigned char *)str;
	while (size--)
		*string++ = 0;
}
