/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:09:32 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/09 17:09:32 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**get_flags(void)
{
	char **flags;

	flags = malloc(sizeof(char *) * 2);
	flags[0] = "-n";
	flags[1] = "\0";
	return (flags);
}

void	ft_echo(char **line)
{
	t_sep	arg;
	char	**flags;

	flags = get_flags();
	arg = seperate_flags(line, flags, '*');
}