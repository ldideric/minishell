/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:28:53 by ldideric      #+#    #+#                 */
/*   Updated: 2020/12/07 22:38:31 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Includes
*/

# include <unistd.h>

# include <libft.h>

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
void					ms_error(char *message, char *var);
char					**state(char *s);
int						realloc_state(char **s, char c, int new);
t_sep					seperate_flags(char **args, char **flags, char c);
void					free_line(char **line);
void					ft_exec(char **line);
int						is_path(char *str);

/*
** Env Util Functions
 */

t_var					*read_var(char *s);
void					new_env(char *value);
char					*get_env(char *str);
void					del_env(char *str);
t_var					**get_var_arr();
int						var_len(t_var **arr);
char					**env_to_charray(t_var **env);
char					*env_to_char(t_var *env);
void					update_environ(t_var **env);
t_var					**add_var(t_var **env, t_var *value);

#endif
