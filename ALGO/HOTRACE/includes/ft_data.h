/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 03:52:45 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 01:49:17 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H
t_sizetree	*ft_init_data();
void	ft_add_data(t_sizetree *root, char *key, char *value);
char	*ft_get_data(char *key, t_sizetree *root);
void	ft_search_data(t_sizetree *root);
#endif /* !FT_DATA_H */
