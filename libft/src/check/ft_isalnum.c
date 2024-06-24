/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 06:08:04 by ychng             #+#    #+#             */
/*   Updated: 2024/04/21 06:10:47 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Check if the character is an alphanumeric character
// (either a letter or a digit).
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
