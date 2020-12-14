/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:47:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/12/14 17:10:46 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_cfunc		specifier(char *s)
{
	t_cfunc					ret;
	static const t_cfunc	func[8] = {
		[0] = &ft_exit,
		[1] = &ft_echo,
		[2] = &ft_pwd,
		[3] = &ft_env,
		[4] = &ft_export,
		[5] = &ft_unset,
		[6] = &ft_cd,
		[7] = &ft_clear,
	};

	ret = NULL;
	ret = (ft_strncmp(s, "exit", INT_MAX) == 0) ? func[0] : ret;
	ret = (ft_strncmp(s, "echo", INT_MAX) == 0) ? func[1] : ret;
	ret = (ft_strncmp(s, "pwd", INT_MAX) == 0) ? func[2] : ret;
	ret = (ft_strncmp(s, "env", INT_MAX) == 0) ? func[3] : ret;
	ret = (ft_strncmp(s, "export", INT_MAX) == 0) ? func[4] : ret;
	ret = (ft_strncmp(s, "unset", INT_MAX) == 0) ? func[5] : ret;
	ret = (ft_strncmp(s, "cd", INT_MAX) == 0) ? func[6] : ret;
	ret = (ft_strncmp(s, "clear", INT_MAX) == 0) ? func[7] : ret;
	free(s);
	return (ret);
}

int				parser(char **line)
{
	t_cfunc func;

	if (is_path(line[0]))
	{
		ft_exec(line);
		return (127);
	}
	func = specifier(ft_strmapi(line[0], &ft_mapi_low));
	if (func == NULL)
	{
		ms_error("command not found: %s", line[0]);
		return (127);
	}
	return (func(line + 1));
}

void				mini_init(void)
{
	int			i;

	i = 0;
	g_data = malloc(sizeof(t_data));
	del_env("OLDPWD");
}

int					main(void)
{
	char			*line;
	char			**commands;
	unsigned char	ret;

	ret = 0;
	mini_init();
	ft_printf(CLEAR);
	while (1)
	{
		ft_printf("%-5d%s", ret, USER);
		get_next_line(STDIN_FILENO, &line);
		commands = ft_split(line, ';');
		while (*commands)
		{
			ret = parser(ft_split(*commands, ' '));
			commands++;
		}
		free(line);
	}
	return (0);
}
