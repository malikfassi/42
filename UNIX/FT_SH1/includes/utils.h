/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:28:22 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/27 18:21:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

# include <libft.h>
char	**find(char **src, char *to_find);
int		findi(char **src, char *to_find);
int		len_arr(char **arr);
char	*ft_strtoupper(char *str);
char	*ft_strnjoin(char const *s1, char const *s2, size_t len_s2);
#endif
