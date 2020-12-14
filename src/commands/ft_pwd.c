/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 18:43:55 by ldideric      #+#    #+#                 */
/*   Updated: 2020/12/07 21:35:14 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_pwd(char **line)
{
	(void)line;
	ft_printf("%s\n", getcwd(NULL, 0));
}
