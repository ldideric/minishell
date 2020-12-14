/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unset.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:43:19 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/14 16:31:55 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_unset(char **line)
{
	if (!*line)
	{
		ms_error("unset: not enough arguments", NULL);
		return (1);
	}
	while (*line)
	{
		del_env(*line);
		line++;
	}
	return (0);
}
