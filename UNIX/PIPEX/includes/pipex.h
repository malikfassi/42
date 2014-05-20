/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 14:07:56 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/31 16:13:20 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>

void	free_arr(char ***arr);
char	*get_path(char **envp, char **cmd);
int		ft_access(char *path);
void	ft_putendl_fd(char const *s, int fd);
void	*ft_memalloc(size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strcat(char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strdel(char **as);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s1);
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
char	*search_path(char **paths, char *cmd);
char	**find(char **src, char *to_find);
int		findi(char **src, char *to_find);
char	*ft_strtoupper(char *str);
int		len_arr(char **arr);
char	*ft_strnjoin(char const *s1, char const *s2, size_t len_s2);
char	*ft_strcpy(char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);

#endif
