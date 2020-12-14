/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmelis <jmelis@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 21:41:10 by jmelis        #+#    #+#                 */
/*   Updated: 2020/11/02 16:59:47 by jmelis        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*base_errors(int code)
{
	char	*errors[4];

	code *= -1;
	errors[0] = "Something went wrong while reading errormessages.txt";
	errors[1] = "File should have %s extention";
	errors[2] = "Something went wrong while opening file with path: '%s'";
	errors[3] = "Executable's name should be: '%s'";
	return (errors[code]);
}

char	*get_errors(char *em_path, int code)
{
	int		fd;
	int		ret;
	char	*str;
	int		i;

	if (code < 1)
		return (base_errors(code));
	fd = ft_validate_file(em_path, "", "*");
	ret = 1;
	i = 0;
	while (ret == 1 && code != i)
	{
		ret = get_next_line(fd, &str);
		if (ret < 0)
			return (base_errors(-1));
		i++;
	}
	return (str);
}

void	ft_error(int code, char *arg)
{
	char *error;

	error = get_errors("errormessages.txt", code);
	if (code < 0)
		code = 0;
	ft_putstr_fd("Error\n", 0);
	ft_printf(error, arg);
	exit(1);
}
