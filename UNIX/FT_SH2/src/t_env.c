/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:27:15 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/26 18:28:57 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static t_env	*new_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env *));
	if (env)
	{
		env->cmds = NULL;
		env->envp = NULL;
	}
	return (env);
}

t_env	*get_env(void)
{
	static t_env	*env = NULL;

	if (env == NULL)
		env = new_env();
	return (env);
}

void	set_envp(t_env *env, char ** envp)
{
	env->envp = envp;
}
