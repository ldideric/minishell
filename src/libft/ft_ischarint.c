/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ischarint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 19:29:29 by root          #+#    #+#                 */
/*   Updated: 2020/12/07 16:51:55 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_ischarint(char *str, char c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == c || str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
