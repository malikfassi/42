/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 19:22:30 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/27 18:20:08 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_PATH_H
# define SEARCH_PATH_H

# include <dirent.h>
# include <libft.h>
char	*reduce_one_slash_front(char *cmd);
char	*search_path(char **paths, char *cmd);

#endif
