/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 15:01:32 by ldideric      #+#    #+#                 */
/*   Updated: 2021/01/07 15:06:10 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_arrdup(char **str)
{
	char	**new;
	int		j;

	j = 0;
	if (!str)
		return (NULL);
	while (str[j] != NULL)
		j++;
	new = malloc(sizeof(char *) * (j + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (str[j] != NULL)
	{
		new[j] = ft_strdup(str[j]);
		j++;
	}
	new[j] = NULL;
	return (&new[0]);
}
