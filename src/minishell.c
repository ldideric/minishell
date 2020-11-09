/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:47:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 18:07:44 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char			*user = "\x1b[38;5;129mUser» ";

static t_cfunc		specifier(char *s)
{
	t_cfunc					ret;
	static const t_cfunc	func[4] = {
//		[0] = &exit,
		[1] = &ft_echo,
	};

	ret = NULL;
//	ret = (ft_strncmp(s, "exit", 4) == 0) ? func[0] : ret;
	ret = (ft_strncmp(s, "echo", 4) == 0) ? func[1] : ret;
	free(s);
	return (ret);
}

void				parser(char **line)
{
	t_cfunc func;

	func = specifier(ft_strmapi(line[0], &ft_mapi_low));
	if (func == NULL)
	{
		ft_printf("msh: command not found: %s", line[0]);
		return ;
	}
	func(line + 1);
	ft_printf("%s\n", line);
}

int					main(void)
{
	char	*line;

	ft_printf(CLEAR);
	while (1)
	{
		ft_printf(user);
		get_next_line(STDIN_FILENO, &line);
		parser(ft_split(line, ' '));
		free(line);
	}
	return (0);
}
