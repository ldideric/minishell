/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:47:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/23 21:09:25 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_cfunc		specifier(char *s)
{
	t_cfunc					ret;
	static const t_cfunc	func[4] = {
		[0] = &ft_exit,
		[1] = &ft_echo,
		[2] = &ft_pwd,
	};

	ret = NULL;
	ret = (ft_strncmp(s, "exit", INT_MAX) == 0) ? func[0] : ret;
	ret = (ft_strncmp(s, "echo", INT_MAX) == 0) ? func[1] : ret;
	ret = (ft_strncmp(s, "pwd", INT_MAX) == 0) ? func[2] : ret;
	free(s);
	return (ret);
}

void				parser(char **line)
{
	t_cfunc func;
	int i = 0;

	while (line[i] != NULL)
		ft_printf("%s$", line[i]);
	func = specifier(ft_strmapi(line[0], &ft_mapi_low));
	if (func != NULL)
		func(line + 1);
	else
		ft_printf("msh: command not found: %s\n", line[0]);
	free_line(line);
}

int					main(void)
{
	char	*line;

	ft_printf(CLEAR);
	while (1)
	{
		ft_printf(USER);
		get_next_line(STDIN_FILENO, &line);
		parser(state(line));
		free(line);
	}
	return (0);
}
