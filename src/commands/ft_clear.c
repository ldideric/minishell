/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clear.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 16:47:31 by jmelis        #+#    #+#                 */
/*   Updated: 2021/01/07 17:36:52 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_clear(char **line)
{
	ft_printf(CLEAR);
	return (0);
}
