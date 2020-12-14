/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_file.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:37:49 by jmelis        #+#    #+#                 */
/*   Updated: 2020/12/07 21:34:20 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		compare(char *file_path, va_list *ap, char *s)
{
	while (s != NULL)
	{
		if (ft_strncmp(s, file_path, INT_MAX) == 0)
			return (1);
		s = va_arg(*ap, char *);
	}
	return (0);
}

int		check_extentions(char *file_path, va_list *ap)
{
	char *s;

	s = va_arg(*ap, char *);
	if (s[0] == '*')
		return (1);
	while (*file_path)
	{
		if (*file_path == '.')
			return (compare(file_path, ap, s));
		file_path--;
	}
	return (0);
}

int		ft_validate_file(char *file_path, char *error, ...)
{
	char	*path;
	int		ret;
	va_list	ap;
	int		i;

	va_start(ap, error);
	i = 0;
	ret = 0;
	path = file_path;
	while (*file_path)
		file_path++;
	file_path--;
	if (check_extentions(file_path, &ap) == 0)
		ft_error(-1, error);
	ret = open(path, O_RDONLY);
	if (ret < 0)
		ft_error(-2, path);
	va_end(ap);
	return (ret);
}
