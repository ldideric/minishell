/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:26:43 by ldideric      #+#    #+#                 */
/*   Updated: 2020/12/07 18:17:42 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_sep
{
	char				**args;
	char				**flags;
}						t_sep;

typedef struct			s_var
{
	char				*name;
	char				*value;
}						t_var;

typedef struct			s_data
{
	int					exitcode;
	char				*prevdir;
}						t_data;

typedef struct			s_res
{
	int					x;
	int					y;
}						t_res;

typedef struct			s_state
{
	char				c;
	int					on;
}						t_state;

#endif
