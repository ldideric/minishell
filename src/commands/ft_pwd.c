/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 18:43:55 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 19:02:46 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_pwd(char **line)
{
	(void)line;
	ft_printf("%s", getcwd(NULL, 0));
}
