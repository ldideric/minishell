/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 18:43:55 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/14 17:31:24 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_pwd(char **line)
{
	(void)line;
	ft_printf("%s\n", getcwd(NULL, 0));
}
