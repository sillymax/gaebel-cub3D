/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:22:46 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 20:23:17 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	isspecifier(char c)
{
	char	specifiers[10];

	ft_strcpy(specifiers, "cspdiuxX%");
	return (ft_strchr(specifiers, c));
}
