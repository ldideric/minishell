/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:00:36 by root          #+#    #+#                 */
/*   Updated: 2020/11/14 19:39:51 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_cd(char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i])
		i++;
	if (i > 1)
		ft_error("cd: too many arguments", NULL);
	if (!ft_strncmp(*line, "-", INT_MAX))
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