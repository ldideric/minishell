/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 21:33:10 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:33:12 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	new_env(char *value)
{
	t_var	**env;
	t_var	**newenv;
	t_var	*newvar;

	newvar = read_var(value);
	if (newvar == NULL)
		return ;
	env = get_var_arr();
	newenv = ft_calloc(sizeof(t_var *), var_len(env) + 2);
	newenv = add_var(env, newvar);
	update_environ(newenv);
}

char	*get_env(char *str)
{
	int			i;
	t_var		**env;

	env = get_var_arr();
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i]->name, str, INT_MAX) == 0)
			return (env[i]->value);
		i++;
	}
	return ("");
}

void	del_env(char *str)
{
	t_var	**newenv;
	t_var	**oldenv;
	int		i;
	int		j;

	oldenv = get_var_arr();
	j = 0;
	i = 0;
	newenv = ft_calloc(sizeof(t_var *), var_len(oldenv) + 1);
	while (oldenv[i])
	{
		if (ft_strncmp(oldenv[i]->name, str, INT_MAX) != 0)
		{
			newenv[j] = oldenv[i];
			j++;
		}
		i++;
	}
	update_environ(newenv);
}
