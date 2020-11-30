/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:00:36 by root          #+#    #+#                 */
/*   Updated: 2020/11/30 19:35:40 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_cd(char **line)
{
	int		i;
	char	*tmp;

	(void)line;
	data = g_data;
	i = 0;
	begin = g_data->env;
	while (*g_data->env)
	{
		free(*line);
		*line = g_data.prevdir;
		ft_printf("%s\n", *line);
	}
	tmp = g_data.prevdir;
	g_data.prevdir = getcwd(NULL, 0);
	if (chdir(*line) != 0)
	{
		ft_error("cd: %s: No such file or directory", *line);
		g_data.prevdir = tmp;
	}
}