/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:29:53 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/09 17:29:53 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.c>

void		check_flags(char *arg, char **flags)
{
    while (*flags)
    {
        if (ft_strncmp(arg, *flags))
        	return ;
        flags++;
    }
	ft_printf("error");
}

t_sep		flags(char **args, char **flags)
{
    t_sep	ret;
    int		x;
    int 	y;

    ret = malloc(sizeof(t_sep));
    y = 0;
    x = 0;
    while (*args)
    {
        if (**args == '-')
        {
            check_flags(args[i], flags)
            ft_realloc_arr(&ret.flags, &x)
            ret.flags[x] = *args;
            x++;
        }
        else
		{
        	ft_realloc_arr(&ret.args, &y)
        	ret.args[y] = *args;
        	y++;
		}
        args++;
    }
    return (ret);
}