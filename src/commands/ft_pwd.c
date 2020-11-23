/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 18:43:55 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/23 18:53:32 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_pwd(char **line)
{
	int i;

	i = 0;
	if (line[0] != NULL)
	{
		if (line[0][0] == '-')
		{
			while (line[0][i] == '-')
				i++;
			ft_printf("pwd: bad option: -%c\n", line[0][i]);
		}
		else
			ft_printf("pwd: too many arguments\n");
	}
	else
		ft_printf("%s\n", getcwd(NULL, 0));
}
