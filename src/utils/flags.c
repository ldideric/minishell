/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:29:53 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/09 20:54:17 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int			check_flags(char *arg, char **flags)
{
	while (*flags)
	{
		if (ft_strncmp(arg, *flags, INT_MAX))
			return (1);
		flags++;
	}
	return (0);
}

void		norm(char **args, t_sep *ret, int *y)
{
	ret->args = ft_realloc_arr(&ret->args, y);
	ret->args[*y] = *args;
	y[0]++;
}

void		null_character(t_sep *ret, t_res xy)
{
	ft_realloc_arr(&ret->flags, &xy.x);
	ft_realloc_arr(&ret->args, &xy.y);
	ret->flags[xy.x] = malloc(sizeof(char));
	ret->flags[xy.x][0] = '\0';
	ret->args[xy.y] = malloc(sizeof(char));
	ret->args[xy.y][0] = '\0';
}

t_sep		seperate_flags(char **args, char **flags, char c)
{
	t_sep	ret;
	t_res	xy;

	xy = (t_res){0, 0};
	while (*args)
	{
		if (**args == '-')
		{
			if (!check_flags(*args, flags) && c != '*')
				ft_printf("error");
			if (check_flags(*args, flags))
			{
				ft_realloc_arr(&ret.flags, &xy.x);
				ret.flags[xy.x] = *args;
				xy.x++;
			}
		}
		else
			norm(args, &ret, &xy.y);
		args++;
	}
	null_character(&ret, xy);
	return (ret);
}
