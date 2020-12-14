/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_utils2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 21:32:50 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:32:54 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*env_to_char(t_var *env)
{
	char *ret;
	char *tmp;

	tmp = ft_strjoin(env->name, "=");
	ret = ft_strjoin(tmp, env->value);
	free(tmp);
	return (ret);
}

char	**env_to_charray(t_var **env)
{
	char	**ret;
	int		i;
	int		b;

	b = var_len(env);
	i = 0;
	ret = malloc(sizeof(t_var *) * (b + 1));
	while (env[i])
	{
		ret[i] = env_to_char(env[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	update_environ(t_var **env)
{
	extern char **environ;

	environ = env_to_charray(env);
}

int		var_exist(t_var **env, t_var *value)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i]->name, value->name, INT_MAX) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_var	**add_var(t_var **env, t_var *value)
{
	t_var	**newenv;
	int		i;
	int		var;

	var = var_exist(env, value);
	newenv = malloc((var_len(env) + (2 - var)) * sizeof(t_var *));
	if (newenv == NULL)
		ft_error(-1, "(t_var) newenv in add_var");
	i = 0;
	while (env[i])
	{
		if (var && ft_strncmp(value->name, env[i]->name, INT_MAX) == 0)
		{
			newenv[i] = value;
			i++;
			continue ;
		}
		newenv[i] = env[i];
		i++;
	}
	if (!var)
	{
		newenv[i] = value;
		i++;
	}
	newenv[i] = NULL;
	return (newenv);
}
