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

int         check_flags(char *arg, char **flags)
{
    while (*flags)
    {
        if (ft_strncmp(arg, *flags))
            return (1);
        flags++;
    }
    return (0);
}

t_sep       flags(char **args, char **flags)
{
    t_sep ret;

    ret = malloc(sizeof(t_sep));
    
    while (*args)
    {
        if (**args == '-')
        {
            if (!check_flags(args[i], flags))
                ft_printf("error");
            else
            {
                ft_realloc_arr()
            }
        }
        args++;
    }
}