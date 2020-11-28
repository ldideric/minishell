/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aborthandler.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 21:24:09 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/28 21:32:57 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	aborthandler(int signum)
{
	ft_printf("%d\n", signum);
}