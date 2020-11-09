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
	char *flags[2];

	flags[0] = "-n";
	flags[1][0] = '\0';
	return (flags);
}

int		ft_echo(char **args)
{
	t_sep	arg;
	char	**flags;

	flags = get_flags();
	arg = flags(args, g_flags)
}