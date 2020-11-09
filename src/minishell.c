/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:47:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 17:16:05 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		specifier(char *s, t_base *b)
{
	static const t_read	spec[4] = {
		[0] = &rd_tex,
		[1] = &rd_res,
		[2] = &rd_f_c,
		[3] = &rd_spr,
	};

	return (((*(u_int16_t *)s == *(u_int16_t *)"NO") && spec[0](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"EA") && spec[0](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"SO") && spec[0](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"WE") && spec[0](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"R ") && spec[1](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"F ") && spec[2](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"C ") && spec[2](s, b)) ||
			((*s == *"S") && spec[3](s, b)));
}

void		parser(char *line)
{
	if (ft_strncmp(line, "exit", 0))
		exit(0);
	ft_printf(CLEAR);
	ft_printf("%s\n", line);
}

int			main(void)
{
	char	*line;

	while (1)
	{
		ft_printf("User» ");
		get_next_line(STDIN_FILENO, &line);
		parser(line);
	}
	return (0);
}
