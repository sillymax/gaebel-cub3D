/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:40:57 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 20:08:35 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTPUT_H
# define FT_OUTPUT_H

// ft_snprintf header
# include "ft_snprintf.h"

// Output functions
void	ft_putchr_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

#endif