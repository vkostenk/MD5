/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:26:51 by vkostenk          #+#    #+#             */
/*   Updated: 2018/09/18 18:37:52 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder/ft_ssl.h"

int		main(int argc, char **argv)
{
	t_message m;

	init_flags(&m);
	if (argc <= 1)
		ft_printf("usage: ./ft_ssl command [command opt] [command args]\n");
	else if (ft_strcmp(argv[1], "md5") == 0
		|| ft_strcmp(argv[1], "sha256") == 0)
	{
		if (argc < 3)
			case_no_arg(argv[1], m, 0);
		else
		{
			while (argv[m.arg] && argv[m.arg][0] == '-')
				case_flags(argv[1], &m, argv[m.arg], argv[m.arg + 1]);
			if (!argv[m.arg] && ft_strchr("qr", argv[m.arg - 1][1]))
				case_no_arg(argv[1], m, 0);
		}
		while (m.arg < argc)
			case_arg(argv[1], argv[m.arg++], m, m.flags[1]);
	}
	else
		ft_error(argv[1], 0, 0);
	return (0);
}

void	init_flags(t_message *m)
{
	m->flags[0] = 2;
	m->flags[1] = 1;
	m->arg = 2;
}

void	ft_error(char *comand, char option, int bool)
{
	if (!bool)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", comand);
		ft_printf("Standard commands:\nMessage Digest commands:\nmd5");
	}
	else
	{
		ft_printf("%s: illegal option -- %c\n", comand, option);
		ft_printf("usage: %s [-pqr] [-s string] [files ...]\n", comand);
	}
	exit(-1);
}

void	case_flags(char *comand, t_message *m,
	char *arg, char *nextarg)
{
	m->i = 0;
	while (arg && arg[++m->i] && ft_strchr("pqrs", arg[m->i]))
	{
		if (arg[m->i] == 'r' && m->flags[0] != 0)
		{
			m->flags[0] = 4;
			m->flags[1] = 3;
		}
		else if (arg[m->i] == 'q')
		{
			m->flags[0] = 0;
			m->flags[1] = 0;
		}
		else if (arg[m->i] == 'p')
			case_no_arg(comand, *m, 5);
		else if (arg[m->i] == 's')
		{
			case_string(comand, nextarg, *m, m->flags[0]);
			m->arg++;
		}
	}
	if (arg && arg[m->i] != '\0')
		ft_error(comand, arg[m->i], 1);
	m->arg++;
}
