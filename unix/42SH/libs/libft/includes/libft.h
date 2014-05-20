/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:32:40 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 17:22:49 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "libft_struct.h"

int		ft_arrsize(char **arr);
int		ft_arradd(char ***arr, char *str);
int		ft_arridel(char ***arr, size_t index);
void	ft_arrdel(char ***arr);
void	ft_arrfree(char ***arr, size_t size);
void	ft_arriter(char **arr, void (*f)(char *));
void	ft_arriteri(char **arr, void (*f)(unsigned int, char *));
char	**ft_arrnew(size_t size);
char	**ft_arrdup(char **arr);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
void	ft_clstadd_after(t_clist **aclst, t_clist *new);
void	ft_clstadd_before(t_clist **aclst, t_clist *new);
void	ft_clstdel(t_clist **aclst, void (*del)(void *, size_t));
void	ft_clstdelone(t_clist **aclst, void (*del)(void *, size_t));
void	ft_clstiter(t_clist *clst, void (*f)(t_clist *elem));
size_t	ft_clstlen(t_clist *clst);
t_clist	*ft_clstnew(void const *content, size_t content_size);
void	ft_dlstadd_after(t_dlist **adlst, t_dlist *new);
void	ft_dlstadd_before(t_dlist **adlst, t_dlist *new);
void	ft_dlstadd_end(t_dlist **adlst, t_dlist *new);
void	ft_dlstadd_first(t_dlist **adlst, t_dlist *new);
void	ft_dlstdel(t_dlist **adlst, void (*del)(void *, size_t));
void	ft_dlstdel_fwd(t_dlist **adlst, void (*del)(void *, size_t));
void	ft_dlstdel_rwd(t_dlist **adlst, void (*del)(void *, size_t));
void	ft_dlstdelone(t_dlist **adlst, void (*del)(void *, size_t));
void	ft_dlstiter(t_dlist *dlst, void (*f)(t_dlist *elem));
void	ft_dlstiter_fwd(t_dlist *dlst, void (*f)(t_dlist *elem));
void	ft_dlstiter_rwd(t_dlist *dlst, void (*f)(t_dlist *elem));
size_t	ft_dlstlen(t_dlist *dlst);
size_t	ft_dlstlen_fwd(t_dlist *dlst);
size_t	ft_dlstlen_rwd(t_dlist *dlst);
t_dlist	*ft_dlstnew(void const *content, size_t content_size);
int		ft_lstlen(t_list *lst);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstadd_end(t_list *alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list	*ft_lstnew(void const *content, size_t content_size);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_memdel(void **ap);
void	*ft_memalloc(size_t size);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
int		ft_strlen(const char *s);
int		ft_strichr(const char *s, int c);
int		ft_strrichr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strccmp(const char *s1, const char *s2, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_strclr(char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strjump(const char *s, const char *jump);
char	*ft_strdup(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strfjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtolower(char *s);
char	*ft_strtoupper(char *s);
char	**ft_strsplit(char const *s, char c);
int		ft_atoi(const char *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_intlen(int n);
int		ft_fibonacci(int index);
char	*ft_itoa(int n);
char	*ft_realpath(char *path);
char	*ft_implode(char **arr, const char *str);
char	**ft_explode(const char *s, const char *str);

#endif
