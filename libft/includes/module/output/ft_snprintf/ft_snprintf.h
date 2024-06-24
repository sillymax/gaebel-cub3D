/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:04:45 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 20:51:37 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SNPRINTF_H
# define FT_SNPRINTF_H

typedef	struct	s_resultinfo
{
	char	*buffer;
	size_t	size;
}	t_resultinfo;

// utils.c
void	write_tobuffer(t_resultinfo *info, char c);

// specifier/utils.c
bool	isspecifier(char c);

// specifier/handlers_1.c
void	handlechar(t_resultinfo *info, char c);
void	handlestring(t_resultinfo *info, char *str);
void	handlepercent(t_resultinfo *info);

// specifier/handlers_2,c
void	handledigit(t_resultinfo *info, long long num);
void	handlepointer(t_resultinfo *info, uintptr_t ptr);
void	handlelowhex(t_resultinfo *info, unsigned int num);
void	handleupphex(t_resultinfo *info, unsigned int num);

// specifier/handler_3.c
void	handlespecifier(t_resultinfo *info, const char *format, va_list args, \
						int *pos);

// ft_snprintf.h
int		ft_snprintf(char *buffer, size_t size, const char *format, ...);

#endif