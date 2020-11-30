/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_export.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:21:52 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/30 19:25:24 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_export(char **line)
{
	if (!*line)
		ft_env(NULL);
	while (*line)
	{
		new_env(*line);
		line++;
	}
}
