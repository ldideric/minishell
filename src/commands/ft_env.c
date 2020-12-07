/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:10:48 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 17:29:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(char **line)
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
}
