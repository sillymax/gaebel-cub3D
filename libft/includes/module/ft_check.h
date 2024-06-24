/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 06:04:34 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 19:26:56 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

// Character check functions
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isxdigit(int c);
int	ft_isblank(int c);
int	ft_isspace(int c);
int	ft_iscntrl(int c);
int	ft_isprint(int c);
int	ft_isgraph(int c);
int	ft_ispunct(int c);
int	ft_isascii(int c);

#endif