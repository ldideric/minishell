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
#include <ft_printf.h>

//static void		free_arr(char **s)
//{
//	int i;
//
//	i = 0;
//	while (s[i][0] != '\n')
//	{
//		free(s[i]);
//		i++;
//	}
//	free(s);
//}

char	**ft_realloc_arr(char ***str, int *size)
{
	char		**d;
	int			i;

	i = 0;
	if (*size == 0)
	{
		d = malloc(1 * sizeof(char *));
		if (d == NULL)
			ft_printf("error");
		return (d);
	}
	d = malloc((*size + 1) * sizeof(char *));
	if (d == NULL)
		ft_printf("error");
	while (i < *size)
	{
		d[i] = str[0][i];
		i++;
	}
	free(str[0]);
	return (d);
}
