/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 21:34:34 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:34:35 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_chdir(char **line, char **dir, char *tmp)
{
	if (chdir(*line) != 0)
		ms_error("cd: %s: No such file or directory", *line);
	else
	{
		*dir = ft_strjoin("PWD=", getcwd(NULL, 0));
		new_env(*dir);
		free(*dir);
		*dir = ft_strjoin("OLDPWD=", tmp);
		new_env(*dir);
		free(*dir);
	}
}

void	ft_cd(char **line)
{
	int		i;
	char	*tmp;
	char	*old;
	char	*dir;

	i = 0;
	old = get_env("OLDPWD");
	tmp = getcwd(NULL, 0);
	if (ft_strncmp(line[0], "-", INT_MAX) == 0)
	{
		if (ft_strncmp("", old, INT_MAX) == 0)
		{
			ms_error("cd: OLDPWD not set", NULL);
			return ;
		}
		free(line[0]);
		line[0] = old;
		ft_printf("%s\n", old);
	}
	g_data->prevdir = getcwd(NULL, 0);
	ft_chdir(line, &dir, tmp);
}
