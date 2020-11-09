/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:28:53 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 19:02:04 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

# include <unistd.h>
# include <limits.h>

# define CLEAR "\e[1;1H\e[2J"

typedef void			(*t_cfunc)(char **line);

typedef struct			s_sep
{
	char				**args;
	char				**flags;
}						t_sep;

void					ft_echo(char **line);
void					ft_exit(char **line);
t_sep					seperate_flags(char **args, char **flags);

#endif
