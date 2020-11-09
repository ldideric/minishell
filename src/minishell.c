/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:47:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 17:44:20 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char			*user = "\x1b[38;5;129mUser» ";

void			ft_exit(char *s);
void			ft_echo(char *s);

static int		specifier(char *s)
{
	t_spec				ret;
	static const t_spec	spec[4] = {
		[0] = &ft_exit,
		[1] = &ft_echo,
	};

	ret = NULL;
	ret = (ft_strncmp(ft_tolower(s), "exit", 4) == 0) ? spec[0] : ret;
	ret = (ft_strncmp(ft_tolower(s), "echo", 4) == 0) ? spec[1] : ret;
	return (ret);
}

void		parser(char **line)
{
	t_spec func;

	func = specifier(line[0]);
	if (func == NULL)
	{
		printf("msh: command not found: %s", line[0]);
		return ;
	}
	func(line + 1);
	ft_printf("%s\n", line);
}

int			main(void)
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
