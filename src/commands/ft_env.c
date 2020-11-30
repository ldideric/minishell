/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:10:48 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/30 19:24:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(char **line)
{
	t_var	**begin;
	int		i;
	t_data	*data;

	(void)line;
	data = g_data;
	i = 0;
	begin = g_data->env;
	while (*g_data->env)
	{
		ft_printf("%s=%s\n", g_data->env[0]->name, g_data->env[0]->value);
		g_data->env++;
	}
	g_data->env = begin;
}
