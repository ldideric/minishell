/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:28:53 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 20:07:41 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <limits.h>

# define CLEAR "\e[1;1H\e[2J"

typedef void			(*t_cfunc)(char **line);

typedef struct			s_sep
{
	char				**args;
	char				**flags;
}						t_sep;

typedef struct			s_data
{
	int					exitcode;
}						t_data;

typedef struct			s_res
{
	int					x;
	int					y;
}						t_res;


t_data					g_data;

void					ft_echo(char **line);
void					ft_exit(char **line);

char					**ft_strsplit(char const *s, char c);
t_sep					seperate_flags(char **args, char **flags, char c);

#endif
