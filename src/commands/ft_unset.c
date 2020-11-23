/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unset.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:43:19 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/23 21:52:59 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_unset(char **line)
{
	while (*line)
	{
		unsetenv(*line);
		line++;
	}
}