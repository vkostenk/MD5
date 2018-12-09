/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:02:54 by vkostenk          #+#    #+#             */
/*   Updated: 2018/09/18 18:35:50 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <fcntl.h>
# include "ft_printf.h"

# define ROTR(x, n)	(((x >> n) | (x << (32 - n))))
# define LEFTROTATE(val, shift)	(((val << shift) | (val >> (32 - shift))))
# define RIGHTSHIFT(val, shift)	(val >> shift)
# define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
# define CH(x,y,z) ((x & y) ^ ((~x) & z))
# define E0(x)	(ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
# define E1(x)	(ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
# define S0(x)	(ROTR(x, 7) ^ ROTR(x, 18) ^ RIGHTSHIFT(x, 3))
# define S1(x)	(ROTR(x, 17) ^ ROTR(x, 19) ^ RIGHTSHIFT(x, 10))

# define BUFFSIZE	500000

# define F(x,y,z) ((x & y) | ((~x) & z))
# define G(x,y,z) ((x & z) | (y & (~z)))
# define H(x,y,z) (x ^ y ^ z)
# define I(x,y,z) (y ^ (x | (~z)))

typedef struct		s_hash
{
	uint32_t		h[8];
}					t_hash;

typedef struct		s_reg
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
	uint32_t		t1;
	uint32_t		t2;
}					t_reg;

typedef struct		s_message
{
	size_t			buffsize;
	unsigned char	*new_mess;
	char			*message;
	int				flags[2];
	int				arg;
	int				i;
}					t_message;

typedef void		(*t_fct) (char *, t_message *);

typedef struct		s_dispatch
{
	int				command;
	t_fct			fct;
}					t_dispatch;

void				ft_sha256(char *str, t_message *m);
void				ft_blocks_sha256(unsigned char *padded, t_hash *h);
void				ft_mainloop_sha256(t_hash *h, uint32_t *m);
void				ft_rotation_sha256(t_reg r, t_hash *h,
	uint32_t *k, uint32_t *w);
uint32_t			*ft_reg_sha256(void);

void				ft_md5(char *str, t_message *m);
void				ft_blocks_md5(unsigned char *padded, t_hash *h);
void				ft_rotation_md5(t_reg *r, uint32_t *m,
	uint32_t *k, uint32_t *s);
void				ft_mainloop_md5(t_hash *h, uint32_t *m);
uint32_t			*ft_reg_md5(void);

void				ft_message_sha256(char *str, t_message *m);
void				ft_message_new(t_message *m, t_hash h, int len_hash);
void				ft_message_md5(char *str, t_message *m);

uint64_t			swap_uint64(uint64_t val);
uint32_t			swap_uint32(uint32_t val);

char				*ft_fd_to_str(int fd);
char				*str_upper(char *str);
char				*str_lower(char *str);
int					ft_validfile(char *comand, char *arg);

void				init_flags(t_message *m);
void				ft_error(char *comand, char option, int bool);
void				case_flags(char *comand, t_message *m,
	char *argument, char *nextarg);

void				ft_printhash(char *str, char *comand,
	t_message m, char flags);
char				*ft_command(char *comand, t_message *m, int fd);
void				case_no_arg(char *comand, t_message m, char flags);
void				case_arg(char *comand, char *arg,
	t_message m, char flags);
void				case_string(char *comand, char *str,
	t_message m, char flags);

#endif
