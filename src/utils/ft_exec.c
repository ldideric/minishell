/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exec.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 21:33:54 by jmelis        #+#    #+#                 */
/*   Updated: 2021/01/07 17:37:43 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exec(char **line)
{
	extern char **environ;
	int			status;
	int			ret;

	ret = fork();
	if (ret == 0)
	{
		if (execve(line[0], line + 1, environ) < 0)
			ms_error("zsh: no such file or directory: %s", line[0]);
	}
	else if (ret > 0)
	{
		wait(&status);
		if (status >= 0)
			ft_printf("[%d] ", status / 256);
	}
	else
		ft_error(7, "");
}
