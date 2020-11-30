/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:00:36 by root          #+#    #+#                 */
/*   Updated: 2020/11/30 20:44:44 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_cd(char **line)
{
	int		i;
	char	*tmp;
	char	*dir;

	i = 0;
	tmp = g_data->prevdir;
	g_data->prevdir = getcwd(NULL, 0);
	if (chdir(*line) != 0)
	{
		ft_error("cd: %s: No such file or directory", *line);
		free(g_data->prevdir);
		g_data->prevdir = tmp;
	}
	else
	{
		dir = ft_strjoin("PWD=", getcwd(NULL, 0));
		new_env(dir);
		free(dir);
	}
}