/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:46:19 by ychng             #+#    #+#             */
/*   Updated: 2024/06/24 23:45:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

// String functions
int		ft_strlen(const char *str);
int		ft_strspn(const char *str, const char *accept);
int		ft_rstrspn(const char *str, const char *accept);
int		ft_strcspn(const char *str, const char *reject);
int		ft_rstrcspn(const char *str, const char *reject);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strchr(const char *str, int c);
char	*ft_rstrchr(const char *str, int c);
char	*ft_strpbrk(const char *str, const char *accept);
char	*ft_strcpbrk(const char *str, const char *reject);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, int n);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, int n);
char	*ft_substr(const char *str, int start, int len);
char	*ft_subdel(const char *str, int start, int len);
char	*ft_strtrim(const char *str, const char *delim);
char	*ft_strjoin(const char *s1, const char *s2, int free_option);
char	*ft_strins(const char *original, const char *insert, int pos);
char	*ft_strtok(char *str, const char *delim);
char	**ft_split(const char *str, const char *delim);
void	ft_strrev(char *str);

#endif