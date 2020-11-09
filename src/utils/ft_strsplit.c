/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 14:01:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/09 19:56:27 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

typedef struct	s_split
{
	char		c;
	char		*s;
	char		**arr;
	int			i;
	int			j;
}				t_split;

t_split			g_sp;

static char		*ft_strcut(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (*s != g_sp.c && *s != '\0')
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

static char		**ft_strclear(void)
{
	int i;

	i = 0;
	while (g_sp.arr[i])
	{
		free(g_sp.arr[i]);
		i++;
	}
	free(g_sp.arr);
	return (NULL);
}

static char		**split_loop(void)
{
	int		i;
	int		str_cntr;

	i = 0;
	str_cntr = 0;
	while (g_sp.s[i] != '\0')
	{
		while (g_sp.s[i] == g_sp.c)
			i++;
		if (g_sp.s[i] != g_sp.c && g_sp.s[i] != '\0')
		{
			g_sp.arr[str_cntr] = ft_strcut(g_sp.s + i);
			if (!g_sp.arr[str_cntr])
				return (ft_strclear());
			str_cntr++;
			while (g_sp.s[i] != g_sp.c && g_sp.s[i] != '\0')
				i++;
		}
	}
	g_sp.arr[str_cntr] = NULL;
	return (g_sp.arr);
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	g_sp.arr = malloc(sizeof(char *) * 2);
	if (!g_sp.arr)
		return (NULL);
	g_sp.i = 0;
	g_sp.j = 0;
	g_sp.arr = split_loop();
	if (!g_sp.arr)
	{
		;
		return (ft_strclear());
	}
	return (g_sp.arr);
}
