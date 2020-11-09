/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 18:46:23 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/24 22:01:19 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	if (str1 == NULL && str2 == NULL)
		return (0);
	if (str1 == NULL || str2 == NULL)
		return (1);
	while (str2[i] && str1[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i < n && ((str2[i] && !str1[i]) || (str1[i] && !str2[i])))
		return (str1[i] - str2[i]);
	return (0);
}