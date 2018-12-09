/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:16:26 by vkostenk          #+#    #+#             */
/*   Updated: 2018/09/18 18:37:21 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder/ft_ssl.h"

int		ft_validfile(char *command, char *arg)
{
	int filedes;

	if ((filedes = open(arg, O_RDONLY)) == -1)
		ft_printf("%s: %s: No such file or directory\n", command, arg);
	return (filedes);
}

char	*ft_fd_to_str(int fd)
{
	char	*str;
	int		num_read_char;
	char	*temp;
	char	buff[BUFFSIZE];

	str = ft_strnew(0);
	while ((num_read_char = read(fd, &buff, BUFFSIZE)) > 0)
	{
		buff[num_read_char] = '\0';
		temp = ft_strjoin(str, buff);
		free(str);
		str = temp;
	}
	return (str);
}

char	*str_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char	*str_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
