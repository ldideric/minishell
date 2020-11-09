/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:09:32 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/09 20:58:14 by ldideric      ########   odam.nl         */
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
		if (ft_strncmp(*arg.flags, "-n", INT_MAX))
			c = 0;
		arg.flags++;
	}
	while (**arg.args)
	{
		ft_printf("%s", *arg.args);
		arg.args++;
	}
	if (c)
		ft_printf("%c", c);
}
