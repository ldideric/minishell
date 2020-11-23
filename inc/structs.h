/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:26:43 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/23 20:02:55 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_sep
{
	char				**args;
	char				**flags;
}						t_sep;

typedef struct			s_data
{
	int					exitcode;
	char				**env;
}						t_data;

typedef struct			s_res
{
	int					x;
	int					y;
}						t_res;

#endif
