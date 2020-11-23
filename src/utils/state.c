/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:12:09 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/23 22:04:15 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int			state_switch(char c, t_state st)
{
	if (st.on == 1)
	{
		if (st.c == c)
		{
			st.on = 0;
			return (1);
		}
		else
			return (0);
	}
	else
	{
		st.c = c;
		st.on = 1;
	}
	return (1);
}

char		**state_loop(char ***arr, char *s, t_state st, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '\"')
			state_switch(s[i], st);
		else if (st.on == 1 && realloc_state(arr, s[i], 0) == 0)
			return (NULL);
		else if (!ft_isprint(s[i]) || s[i] == ' ')
		{
			while (!ft_isprint(s[i]) || s[i] == ' ')
				i++;
			if (realloc_state(arr, s[i], 1) == 0)
				return (NULL);
		}
		else if (realloc_state(arr, s[i], 0) == 0)
			return (NULL);
		i++;
	}
	return (arr);
}

char		**state(char *s)
{
	char		**arr;
	t_state		st;
	int			i;

	i = 0;
	st = (t_state){0, 0};
	while (!ft_isprint(s[i]) || s[i] == ' ')
		i++;
	arr = malloc(sizeof(char *) * 2);
	if (arr == NULL)
		return (NULL);
	arr[0] = malloc(sizeof(char) * 2);
	if (arr[0] == NULL)
		return (NULL);
	arr[0][0] = s[i];
	arr[0][1] = '\0';
	arr[1] = NULL;
	return (state_loop(&arr, s, st, i + 1));
}
