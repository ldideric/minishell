/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_export.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:21:52 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/14 16:30:25 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_export(char **line)
{
	if (!*line)
		ft_env(NULL);
	while (*line)
	{
		new_env(*line);
		line++;
	}
	return (0);
}
