/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 06:26:39 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/27 22:10:19 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

static t_env	*new_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env)
	{
		env->cmds = NULL;
		env->envp = NULL;
		env->datas = NULL;
	}
	return (env);
}

t_env			*get_env(void)
{
	static t_env	*env = NULL;

	if (env == NULL)
		env = new_env();
	return (env);
}
