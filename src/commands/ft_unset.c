/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unset.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:43:19 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:35:37 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_unset(char **line)
{
	if (!*line)
	{
		ft_printf("error\n");
		return ;
	}
	while (*line)
	{
		del_env(*line);
		line++;
	}
}
