/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_export.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:21:52 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:35:05 by jmelis        ########   odam.nl         */
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
