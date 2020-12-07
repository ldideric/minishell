/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 18:21:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/12/07 20:37:52 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_exit(char **line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	if (i > 1)
	{
		ms_error("exit: too many arguments", NULL);
		return ;
	}
	if (i == 1 && !ft_ischarint(*line, ' '))
	{
		ms_error("exit: %s: numeric argument required", *line);
		return ;
	}
	if (i == 0)
		exit(0);
	else
		exit(ft_atoi(*line));
}
