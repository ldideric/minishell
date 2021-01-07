/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc_state.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:56:22 by ldideric      #+#    #+#                 */
/*   Updated: 2021/01/07 17:35:03 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int			realloc_old(char ***s, char c, int i, int j)
{
	char	*tmp;

	while (s[0][j] != NULL)
		j++;
	j--;
	while (s[0][j][i] != '\0')
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (tmp == NULL)
		return (0);
	i = 0;
	while (s[0][j][i] != '\0')
	{
		tmp[i] = s[0][j][i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(s[0][j]);
	s[0][j] = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int			realloc_new(char ***s, char c, int j)
{
	char	**tmp;

	while (s[0][j] != NULL)
		j++;
	tmp = malloc(sizeof(char *) * (j + 2));
	if (tmp == NULL)
		return (0);
	j = 0;
	while (s[0][j] != NULL)
	{
		tmp[j] = ft_strdup(s[0][j]);
		free(s[0][j]);
		j++;
	}
	tmp[j] = malloc(sizeof(char) * 2);
	if (tmp[j] == NULL)
		return (0);
	tmp[j][0] = c;
	tmp[j][1] = '\0';
	tmp[j + 1] = NULL;
	free(s[0]);
	s[0] = ft_arrdup(tmp);
	return (1);
}

int			realloc_state(char ***s, char c, int new)
{
	if (new == 0)
		return (realloc_old(s, c, 0, 0));
	else
		return (realloc_new(s, c, 0));
}
