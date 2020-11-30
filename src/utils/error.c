/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:05:16 by root          #+#    #+#                 */
/*   Updated: 2020/11/14 18:29:02 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_error(char *message, char *var)
{
	ft_printf("msh: ");
	if (var != NULL)
		ft_printf(message, var);
	else 
		ft_printf(message);
	ft_printf("\n");
}