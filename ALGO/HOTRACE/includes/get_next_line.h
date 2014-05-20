/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:48:06 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 20:44:02 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFF_SIZE	5
int	get_next_line(int const fd, char **line);
int	ft_getcode(int code);
void	ft_getcontent(char **buffer, char **line);
char	*ft_concatstr(char *str1, char *str2);
#endif /* !GET_NEXT_LINE_H */
