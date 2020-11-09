/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:47:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 21:21:58 by ldideric      ########   odam.nl         */
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

	func = specifier(ft_strmapi(line[0], &ft_mapi_low));
	if (func == NULL)
	{
		ft_printf("msh: command not found: %s\n", line[0]);
		return ;
	}
	func(line + 1);
}

int					main(void)
{
	char	*line;

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
