/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 21:33:01 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:33:03 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		strleng(char **str)
{
	int i;

	i = 0;
	while (str[0][i] && str[0][i] != '=')
		i++;
	str[0] += i + 1;
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
	b = ft_strlen(s);
	var = malloc(sizeof(t_var));
	var->name = ft_calloc(a + 1, sizeof(char));
	var->value = ft_calloc(b + 1, sizeof(char));
	s = save;
	ft_memccpy(var->name, s, '=', a);
	if (s[a] != '=')
		return (NULL);
	s += a + 1;
	var->name[a] = '\0';
	s = ft_memccpy(var->value, s, '\0', INT_MAX);
	var->value[b] = '\0';
	s = save;
	return (var);
}

int		var_len(t_var **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_var	**get_var_arr(void)
{
	int			i;
	t_var		**ret;
	extern char **environ;

	i = 0;
	while (environ[i])
		i++;
	ret = malloc(sizeof(t_var *) * (i + 1));
	i = 0;
	while (environ[i])
	{
		ret[i] = read_var(environ[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
