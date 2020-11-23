/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 14:01:22 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/23 19:22:23 by ldideric      ########   odam.nl         */
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

t_split			g_s;

static char		**ft_strclear(void)
{
	int i;

	i = 0;
	while (g_s.arr[i])
	{
		free(g_s.arr[i]);
		i++;
	}
	free(g_s.arr);
	return (NULL);
}

static char		*ft_strcut(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (*s != g_s.c && *s != '\0')
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

static char		**split_loop(void)
{
	while (g_s.s[g_s.i] != '\0')
	{
		while (g_s.s[g_s.i] == g_s.c)
			g_s.i++;
		if (g_s.s[g_s.i] != g_s.c && g_s.s[g_s.i] != '\0')
		{
			g_s.arr[g_s.j] = ft_strcut(g_s.s + g_s.i);
			if (!g_s.arr[g_s.j])
				return (ft_strclear());
			g_s.j++;
			while (g_s.s[g_s.i] != g_s.c && g_s.s[g_s.i] != '\0')
				g_s.i++;
		}
	}
	g_s.arr[g_s.j] = NULL;
	return (g_s.arr);
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	g_s.s = (char *)s;
	g_s.c = c;
	g_s.arr = malloc(sizeof(char *) * 2);
	if (!g_s.arr)
		return (NULL);
	g_s.i = 0;
	g_s.j = 0;
	g_s.arr = split_loop();
	return ((g_s.arr) ? g_s.arr : NULL);
}

int				main(int av, char **ac)
{
	char	**s;
	int		i;

	i = 0;
	if (av < 2)
		return (0);
	s = ft_strsplit(ac[1], ' ');
	while (s[i])
	{
		ft_printf("%s\n", s[i]);
		i++;
	}
	return (0);
}
