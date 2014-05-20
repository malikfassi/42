/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:30:14 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 20:11:42 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
#include <stdlib.h>
#include <hotrace.h>
int	ft_strlen(char const *str);
char	*ft_strnew(int size);
void	*ft_memmove(void *s1, const void *s2, int n);
void	ft_bzero(void *byte, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
void	ft_strdel(char **as);
void	ft_memdel(void **ap);
void	ft_strclr(char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
int	ft_max(int a, int b);
int	ft_strcmp(const char *s1, const char *s2);
#endif /* !TOOLS_H */
