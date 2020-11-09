/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:29:53 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/09 20:04:05 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		check_flags(char *arg, char **flags)
{
	while (*flags)
	{
		if (ft_strncmp(arg, *flags, INT_MAX))
			return ;
		flags++;
	}
	ft_printf("error");
}

void		norm(char **args, t_sep *ret, int *y)
{
	ft_realloc_arr(&ret->args, y);
	ret->args[*y] = *args;
	y[0]++;
}

t_sep		seperate_flags(char **args, char **flags, char c)
{
	t_sep	ret;
	t_res	xy;

	xy = (t_res){0, 0};
	while (*args)
		if (**args == '-' && c != '*')
		{
			check_flags(*args, flags);
			ft_realloc_arr(&ret.flags, &xy.x);
			ret.flags[xy.x] = *args;
			xy.x++;
		}
		else
			norm(args, &ret, &xy.y);
	args++;
	return (ret);
}
