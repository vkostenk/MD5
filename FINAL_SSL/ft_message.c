/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 21:30:49 by vkostenk          #+#    #+#             */
/*   Updated: 2018/09/12 21:28:21 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder/ft_ssl.h"

void		ft_message_sha256(char *str, t_message *m)
{
	int			i;
	uint64_t	size;

	size = ft_strlen(str);
	m->buffsize = 64;
	while ((m->buffsize - 8) <= size)
		m->buffsize += 64;
	m->new_mess = (unsigned char *)ft_strnew(m->buffsize);
	i = 0;
	while (str[i])
	{
		m->new_mess[i] = str[i];
		i++;
	}
	m->new_mess[i] = 0x80;
	i = 8;
	size = swap_uint64(size * 8);
	ft_memcpy(&m->new_mess[m->buffsize - i], &size, i);
}

void		ft_message_new(t_message *m, t_hash h, int max)
{
	int		i;
	char	*temp;
	char	*hash;
	char	*message;

	message = ft_strnew(64);
	i = 0;
	while (i < max)
	{
		hash = ft_itoa_base(h.h[i], 16);
		temp = ft_strjoin(message, hash);
		free(message);
		message = temp;
		i++;
	}
	m->message = message;
}

void		ft_message_md5(char *str, t_message *m)
{
	int			i;
	uint64_t	size;

	size = ft_strlen(str);
	m->buffsize = 64;
	while ((m->buffsize - 8) <= size)
		m->buffsize += 64;
	m->new_mess = (unsigned char *)ft_strnew(m->buffsize);
	i = 0;
	while (str[i])
	{
		m->new_mess[i] = str[i];
		i++;
	}
	m->new_mess[i] = 0x80;
	size = size * 8;
	ft_memcpy(&m->new_mess[m->buffsize - 8], &size, 8);
}
