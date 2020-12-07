/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:47:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/12/07 16:14:12 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_cfunc		specifier(char *s)
{
	t_cfunc					ret;
	static const t_cfunc	func[7] = {
		[0] = &ft_exit,
		[1] = &ft_echo,
		[2] = &ft_pwd,
		[3] = &ft_env,
		[4] = &ft_export,
		[5] = &ft_unset,
		[6] = &ft_cd,
	};

	ret = NULL;
	ret = (ft_strncmp(s, "exit", INT_MAX) == 0) ? func[0] : ret;
	ret = (ft_strncmp(s, "echo", INT_MAX) == 0) ? func[1] : ret;
	ret = (ft_strncmp(s, "pwd", INT_MAX) == 0) ? func[2] : ret;
	ret = (ft_strncmp(s, "env", INT_MAX) == 0) ? func[3] : ret;
	ret = (ft_strncmp(s, "export", INT_MAX) == 0) ? func[4] : ret;
	ret = (ft_strncmp(s, "unset", INT_MAX) == 0) ? func[5] : ret;
	ret = (ft_strncmp(s, "cd", INT_MAX) == 0) ? func[6] : ret;
	free(s);
	return (ret);
}

void				parser(char **line)
{
	t_cfunc func;

	func = specifier(ft_strmapi(line[0], &ft_mapi_low));
	if (func == NULL)
	{
		ft_error("command not found: %s", line[0]);
		return ;
	}
	func(line + 1);
}

void				mini_init(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	g_data = malloc(sizeof(t_data));
	while (environ[i])
		i++;
	g_data->env = ft_calloc(i + 1, sizeof(t_var *));
	i--;
	while (environ[i])
	{
		g_data->env[i] = read_var(environ[i]);
		i--;
	}
}

int					main(void)
{
	char	*line;
	char	**commands;

	mini_init();
	ft_printf(CLEAR);
	while (1)
	{
		ft_printf(USER);
		get_next_line(STDIN_FILENO, &line);
		commands = ft_split(line, ';');
		while (*commands)
		{
			parser(state(*commands));
			commands++;
		}
		free(line);
	}
	return (0);
}
