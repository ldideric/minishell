/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:28:53 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/30 20:08:41 by ldideric      ########   odam.nl         */
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

t_data					*g_data;

/*
** Function prototypes
*/

typedef void			(*t_cfunc)(char **line);

/*
** Command Prototypes
*/

void					ft_echo(char **line);
void					ft_exit(char **line);
void					ft_pwd(char **line);
void					ft_env(char **line);
void					ft_export(char **line);
void					ft_unset(char **line);
void					ft_cd(char **line);

/*
** Utils Prototypes
*/


char					**ft_strsplit(char const *s, char c);
void					ft_error(char *message, char *var);
char					**state(char *s);
int						realloc_state(char **s, char c, int new);
t_sep					seperate_flags(char **args, char **flags, char c);
t_var					*read_var(char *s);
void					new_env(char *value);
char					*get_env(char *str);
void					free_line(char **line);
void					del_env(char *str);
void					aborthandler(int signum);

#endif
