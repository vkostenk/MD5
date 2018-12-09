/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:02:46 by vkostenk          #+#    #+#             */
/*   Updated: 2018/09/18 18:36:43 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder/ft_ssl.h"

#define COMMAND 2

t_dispatch	g_comand[] = {
	{0, &ft_md5},
	{1, &ft_sha256}
};

void	ft_printhash(char *str, char *comand, t_message m, char flags)
{
	if (flags == 0)
		ft_printf("%s\n", m.message);
	else if (flags == 1)
		ft_printf("%s (%s) = %s\n", str_upper(comand), str, m.message);
	else if (flags == 2)
		ft_printf("%s (\"%s\") = %s\n", str_upper(comand), str, m.message);
	else if (flags == 3)
		ft_printf("%s %s\n", m.message, str);
	else if (flags == 4)
		ft_printf("%s \"%s\"\n", m.message, str);
	else if (flags == 5)
		ft_printf("%s%s\n", str, m.message);
	str_lower(comand);
}

char	*ft_command(char *comand, t_message *m, int fd)
{
	int		i;
	int		func;
	char	*str;

	func = 0;
	str = ft_fd_to_str(fd);
	if (ft_strcmp(comand, "sha256") == 0)
		func = 1;
	i = 0;
	while (i < COMMAND)
	{
		if (g_comand[i].command == func)
			g_comand[i].fct(str, m);
		i++;
	}
	return (str);
}

void	case_arg(char *comand, char *arg, t_message m, char flags)
{
	int		fd;
	char	*str;

	if ((fd = ft_validfile(comand, arg)) != -1)
	{
		str = ft_command(comand, &m, fd);
		ft_printhash(arg, comand, m, flags);
	}
}

void	case_no_arg(char *comand, t_message m, char flags)
{
	char	*str;

	str = ft_command(comand, &m, 0);
	ft_printhash(str, comand, m, flags);
}

void	case_string(char *comand, char *str, t_message m, char flags)
{
	if (str == NULL)
	{
		ft_printf("option require an argument -- s\n");
		ft_printf("usage: %s [-pqr] [-s string] [files ...]\n", comand);
	}
	else
	{
		if (ft_strcmp(comand, "md5") == 0)
			ft_md5(str, &m);
		else
			ft_sha256(str, &m);
		ft_printhash(str, comand, m, flags);
	}
}
