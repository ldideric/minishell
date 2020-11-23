/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:10:48 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/23 21:56:16 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(char **line)
{
	char **begin;

	begin = g_data->env;
	if (!1 && !line)
		return ;
	while (*g_data->env)
	{
		ft_printf("%s\n", *g_data->env);
		g_data->env++;
	}
	g_data->env = begin;
}
