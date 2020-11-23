/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_export.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:21:52 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/23 22:13:51 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_export(char **line)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (g_data->env[i])
		i++;
	while (line[j])
	{
		g_data->env = ft_realloc_arr(&g_data->env, &i);
		g_data->env[i] = malloc(sizeof(char) * ft_strlen(line[j] + 1));
		ft_strlcpy(g_data->env[i], line[j], ft_strlen(line[j]) + 1);
		i++;
		j++;
	}
}