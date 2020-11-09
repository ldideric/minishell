/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:28:53 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 17:50:46 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

# define CLEAR "\e[1;1H\e[2J"

typedef void			(*t_spec)(char **line);

typedef struct			s_sep
{
	char				**args;
	char				**flags;
}						t_sep;

#endif
