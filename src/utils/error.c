/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 21:32:37 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:32:39 by jmelis        ########   odam.nl         */
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
