/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc_arr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:45:28 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 17:46:55 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		free_arr(char **s)
{
	int i;

	i = 0;
	while (s[i][0] != '\n')
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char			**ft_realloc_arr(char **ptr)
{
	char	**new;
	int		i;

	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (ptr[i][0] != '\0')
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (ptr[i][0] != '\0')
	{
		new[i] = ft_strdup(ptr[i]);
		i++;
	}
	free_arr(ptr);
	return (new);
}
