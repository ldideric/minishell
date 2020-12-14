/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 21:34:41 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:34:42 by jmelis        ########   odam.nl         */
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
	char	c;

	c = '\n';
	flags = get_flags();
	arg = seperate_flags(line, flags, '*');
	while (**arg.flags)
	{
		if (!ft_strncmp(*arg.flags, "-n", INT_MAX))
			c = 0;
		arg.flags++;
	}
	while (**arg.args)
	{
		ft_printf("%s", *arg.args);
		if (**(arg.args + 1))
			ft_printf(" ");
		arg.args++;
	}
	if (c)
		ft_printf("%c", c);
}
