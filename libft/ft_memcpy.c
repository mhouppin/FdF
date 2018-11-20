/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:04:26 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 13:05:30 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		memcpy_not_same_alignement(t_op dstp, t_op srcp, size_t len,
		size_t n_word)
{
	t_op			merge;
	const t_op		shift = srcp % 8;
	const size_t	shr = shift * 8;
	const size_t	shl = (8 - shift) * 8;

	srcp -= shift;
	while (n_word)
	{
		merge = *(t_op *)srcp >> shr | *((t_op *)srcp + 1) << shl;
		*(t_op *)dstp = merge;
		dstp += 8;
		srcp += 8;
		n_word -= 1;
	}
	srcp += shift;
	while (len)
	{
		*(t_byte *)dstp = *(t_byte *)srcp;
		dstp += 1;
		srcp += 1;
		len -= 1;
	}
}

static void		memcpy_same_alignement(t_op dstp, t_op srcp, size_t len,
		size_t n_word)
{
	while (n_word)
	{
		*(t_op *)dstp = *(t_op *)srcp;
		dstp += 8;
		srcp += 8;
		n_word -= 1;
	}
	while (len)
	{
		*(t_byte *)dstp = *(t_byte *)srcp;
		dstp += 1;
		srcp += 1;
		len -= 1;
	}
}

static void		memcpy_no_alignement(t_byte *dst, t_byte *src, size_t len)
{
	while (len)
	{
		*dst = *src;
		dst += 1;
		src += 1;
		len -= 1;
	}
}

void			*ft_memcpy(void *dst, const void *src, size_t len)
{
	t_op	srcp;
	t_op	dstp;

	if (len)
	{
		dstp = (t_op)dst;
		srcp = (t_op)src;
		while (dstp % 8)
		{
			*((t_byte *)dstp) = *((t_byte *)srcp);
			dstp += 1;
			srcp += 1;
			len -= 1;
		}
		if (len > 7)
		{
			if (srcp % 8 == 0)
				memcpy_same_alignement(dstp, srcp, len % 8, len / 8);
			else
				memcpy_not_same_alignement(dstp, srcp, len % 8, len / 8);
		}
		else
			memcpy_no_alignement((t_byte *)dstp, (t_byte *)srcp, len);
	}
	return (dst);
}
