/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:22:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/18 17:25:44 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_COMMANDS_H
# define EXECUTE_COMMANDS_H

int		implemented_function(char **cmd, char ***envp);
char	*get_path(char **envp, char **cmd);
void	non_impl_funct(char **cmd, char **envp);
void	exec_cmds(char ***cmds, char **envp);
#endif
