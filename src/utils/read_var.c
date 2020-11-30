/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_var.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 19:01:44 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/28 20:05:47 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		strleng(char **str)
{
	int i;

	i = 0;
	while (**str && **str != '=')
	{
		str[0]++;
		i++;
	}
	str[0]++;
	return (i);
}

t_var	*read_var(char *s)
{
	t_var	*var;
	char	*save;
	int		a;
	int		b;

	save = s;
	a = strleng(&s);
	b = strleng(&s);
	var = malloc(sizeof(t_var));
	var->name = ft_calloc(a + 1, sizeof(char));
	var->value = ft_calloc(b + 1, sizeof(char));
	s = save;
	ft_memccpy(var->name, s, '=', a);
	s += a + 1;
	var->name[a] = '\0';
	s = ft_memccpy(var->value, s, '\0', INT_MAX);
	var->value[b] = '\0';
	s = save;
	return (var);
}
