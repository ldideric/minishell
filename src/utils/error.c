/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:05:16 by root          #+#    #+#                 */
/*   Updated: 2020/12/07 20:36:29 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ms_error(char *message, char *var)
{
	ft_printf("msh: ");
	if (var != NULL)
		ft_printf(message, var);
	else
		ft_printf(message);
	ft_printf("\n");
}
