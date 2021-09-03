/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:12:09 by ldideric      #+#    #+#                 */
/*   Updated: 2021/01/07 17:31:49 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int			state_switch(char c, t_state *st)
{
	if (st->on == 1)
	{
		if (st->c == c)
		{
			st->on = 0;
			return (1);
		}
		else
			return (0);
	}
	else
	{
		st->c = c;
		st->on = 1;
	}
	return (1);
}

char		**state_loop(char ***arr, char *s, t_state st, int i)
{
	while (s[i] != '\0')
	{
		if ((st.on == 0 && (s[i] == '\'' || s[i] == '\"')) || (s[i] == st.c))
			state_switch(s[i], &st);
		else if (st.on == 1)
		{
			if (st.new == 0 && realloc_state(arr, s[i], 0) == 0)
				return (NULL);
			else if (st.new == 1 && realloc_state(arr, s[i], 1) == 0)
				return (NULL);
			st.new = 0;
		}
		else if (!ft_isprint(s[i]) || s[i] == ' ' && st.on == 0)
			st.new = 1;
		else if (!(!ft_isprint(s[i]) || s[i] == ' ') && st.new == 1)
		{
			if (realloc_state(arr, s[i], 1) == 0)
				return (NULL);
			st.new = 0;
		}
		else if (realloc_state(arr, s[i], 0) == 0)
			return (NULL);
		i++;
	}
	return (*arr);
}

char		**state(char *s)
{
	char		**arr;
	t_state		st;
	int			i;

	i = 0;
	st = (t_state){0, 0, 0};
	while ((!ft_isprint(s[i]) || s[i] == ' ') && s[i] != '\0')
		i++;
	arr = malloc(sizeof(char *) * 2);
	if (arr == NULL)
		return (NULL);
	arr[0] = malloc(sizeof(char) * 2);
	if (arr[0] == NULL)
		return (NULL);
	arr[0][0] = '\0';
	arr[1] = NULL;
	return (state_loop(&arr, s, st, i));
}

