/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 06:03:18 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 19:27:03 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

// Conversion functions
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
double		ft_atof(const char *nptr);
char		*ft_itoa(int num);
char		*ft_lltoa(long long num);

#endif