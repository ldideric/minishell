/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:28:53 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/11 20:44:50 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Includes
*/

# include <unistd.h>
# include <fcntl.h>

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <limits.h>

# include <structs.h>

/*
** Defines
*/

# define CLEAR "\e[1;1H\e[2J"
# define USER "\x1b[38;5;129mUser\x1b[38;5;196m»\x1b[0m "

/*
** Globals
*/

t_data					g_data;

/*
** Function prototypes
*/

typedef void			(*t_cfunc)(char **line);

void					ft_echo(char **line);
void					ft_exit(char **line);
void					ft_pwd(char **line);

char					**ft_strsplit(char const *s, char c);
t_sep					seperate_flags(char **args, char **flags, char c);

void					free_line(char **line);

#endif
