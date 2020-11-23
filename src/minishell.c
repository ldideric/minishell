/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:47:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/23 22:13:20 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdio.h>

static t_cfunc		specifier(char *s)
{
	t_cfunc					ret;
	static const t_cfunc	func[6] = {
		[0] = &ft_exit,
		[1] = &ft_echo,
		[2] = &ft_pwd,
		[3] = &ft_env,
		[4] = &ft_export,
		[5] = &ft_unset,
	};

	ret = NULL;
	ret = (ft_strncmp(s, "exit", INT_MAX) == 0) ? func[0] : ret;
	ret = (ft_strncmp(s, "echo", INT_MAX) == 0) ? func[1] : ret;
	ret = (ft_strncmp(s, "pwd", INT_MAX) == 0) ? func[2] : ret;
	ret = (ft_strncmp(s, "env", INT_MAX) == 0) ? func[3] : ret;
	ret = (ft_strncmp(s, "export", INT_MAX) == 0) ? func[4] : ret;
	ret = (ft_strncmp(s, "unset", INT_MAX) == 0) ? func[5] : ret;
	free(s);
	return (ret);
}

void				parser(char **line)
{
	t_cfunc func;

	func = specifier(ft_strmapi(line[0], &ft_mapi_low));
	if (func != NULL)
		func(line + 1);
	else
		ft_printf("msh: command not found: %s\n", line[0]);
	free_line(line);
}

void				mini_init(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	g_data = malloc(sizeof(t_data));
	while (environ[i])
	{
		g_data->env = ft_realloc_arr(&g_data->env, &i);
		g_data->env[i] = malloc(sizeof(char) * ft_strlen(environ[i] + 1));
		ft_strlcpy(g_data->env[i], environ[i], ft_strlen(environ[i]) + 1);
		i++;
	}
	ft_realloc_arr(&g_data->env, &i);
}

int					main(void)
{
	char		*line;

	mini_init();
	ft_printf(CLEAR);
	while (1)
	{
		ft_printf(USER);
		get_next_line(STDIN_FILENO, &line);
		parser(ft_split(line, ' '));
		free(line);
	}
	return (0);
}
