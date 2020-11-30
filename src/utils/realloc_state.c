/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc_state.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:56:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/23 21:33:04 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int			realloc_old(char **s, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] != NULL)
		j++;
	j--;
	while (s[j][i] != '\0')
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (tmp == NULL)
		return (0);
	i = 0;
	while (s[j][i] != '\0')
	{
		tmp[i] = s[j][i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(s[j]);
	s[j] = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int			realloc_new(char **s, char c)
{
	char	**tmp;
	int		j;

	j = 0;
	while (s[j] != NULL)
		j++;
	tmp = malloc(sizeof(char *) * (j + 2));
	if (tmp == NULL)
		return (0);
	j = 0;
	while (s[j] != NULL)
	{
		tmp[j] = ft_strdup(s[j]);
		free(s[j]);
		j++;
	}
	tmp[j] = malloc(sizeof(char) * 2);
	if (tmp[j] == NULL)
		return (0);
	tmp[j][0] = c;
	tmp[j][1] = '\0';
	tmp[j + 1] = NULL;
	free(s);
	s = tmp;
	return (1);
}

int			realloc_state(char **s, char c, int new)
{
	if (new == 0)
		return (realloc_old(s, c));
	else
		return (realloc_new(s, c));
}
