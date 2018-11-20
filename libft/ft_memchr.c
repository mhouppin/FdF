/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 14:53:42 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 13:09:16 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_op	get_ccopy(int c)
{
	t_op r;

	r = (t_byte)c;
	r |= r << 8;
	r |= r << 16;
	r |= r << 32;
	return (r);
}

static void	*equiv_byte(t_byte *dstp, t_byte c)
{
	if (dstp[0] == c)
		return ((void*)(dstp + 0));
	if (dstp[1] == c)
		return ((void*)(dstp + 1));
	if (dstp[2] == c)
		return ((void*)(dstp + 2));
	if (dstp[3] == c)
		return ((void*)(dstp + 3));
	if (dstp[4] == c)
		return ((void*)(dstp + 4));
	if (dstp[5] == c)
		return ((void*)(dstp + 5));
	if (dstp[6] == c)
		return ((void*)(dstp + 6));
	if (dstp[7] == c)
		return ((void*)(dstp + 7));
	return (NULL);
}

static void	*check_packs(long int dstp, t_op k, size_t len, t_byte c)
{
	t_op r;

	while (len > 0)
	{
		r = *(t_op*)(dstp) ^ k;
		if ((r - 0x0101010101010101UL) & (~r) & 0x8080808080808080UL)
			return (equiv_byte((t_byte*)(dstp), c));
		dstp += OPSIZE;
		len -= 1;
	}
	return (NULL);
}

void		*ft_memchr(const void *s, int c, size_t len)
{
	const t_op	k = get_ccopy(c);
	void		*t;
	long int	dstp;

	dstp = (long int)s;
	if (len >= OPSIZE)
	{
		while (dstp % OPSIZE != 0)
		{
			if (*(t_byte*)(dstp++) == (t_byte)c)
				return ((void*)(dstp - 1));
			len -= 1;
		}
		if ((t = check_packs(dstp, k, len / OPSIZE, (t_byte)c)) != NULL)
			return (t);
		dstp += (len / OPSIZE) * OPSIZE;
		len %= OPSIZE;
	}
	while (len > 0)
	{
		if (*(t_byte*)(dstp++) == (t_byte)c)
			return ((void*)(dstp - 1));
		len -= 1;
	}
	return (NULL);
}
