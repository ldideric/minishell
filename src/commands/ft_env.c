/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 21:34:47 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/14 16:30:09 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_env(char **line)
{
	int			i;
	t_var		**env;

	env = get_var_arr();
	i = 0;
	(void)line;
	while (env[i])
	{
		ft_printf("%s=%s\n", env[i]->name, env[i]->value);
		i++;
	}
	return (0);
}
