/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:34:29 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/30 19:27:51 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	new_env(char *value)
{
	t_var	**new;
	int		i;
	t_var	*newv;

	newv = read_var(value);
	i = 0;
	while (g_data->env[i])
		i++;
	new = ft_calloc(sizeof(t_var *), i + 2);
	i = 0;
	while (g_data->env[i])
	{
		if (ft_strncmp(g_data->env[i]->name, newv->name, INT_MAX) == 0)
		{
			new[i] = newv;
			value = NULL;
			i++;
			continue ;
		}
		new[i] = g_data->env[i];
		i++;
	}
	if (value)
		new[i] = newv;
	g_data->env = new;
}

char	*get_env(char *str)
{
	int i;

	i = 0;
	while (g_data->env[i])
	{
		if (ft_strncmp(g_data->env[i]->name, str, INT_MAX) == 0)
			return (g_data->env[i]->value);
		i++;
	}
	return ("");
}

void	del_env(char *str)
{
	t_var	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g_data->env[i])
		i++;
	new = ft_calloc(sizeof(t_var *), i + 1);
	i = 0;
	while (g_data->env[i])
	{
		if (ft_strncmp(g_data->env[i]->name, str, INT_MAX) != 0)
		{
			new[j] = g_data->env[i];
			j++;
		}
		i++;
	}
	g_data->env = new;
}
