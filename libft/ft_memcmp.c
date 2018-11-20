/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 14:58:47 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 09:56:49 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	nequiv_byte(t_byte *dstp, t_byte *srcp)
{
	if (dstp[0] != srcp[0])
		return (dstp[0] - srcp[0]);
	if (dstp[1] != srcp[1])
		return (dstp[1] - srcp[1]);
	if (dstp[2] != srcp[2])
		return (dstp[2] - srcp[2]);
	if (dstp[3] != srcp[3])
		return (dstp[3] - srcp[3]);
	if (dstp[4] != srcp[4])
		return (dstp[4] - srcp[4]);
	if (dstp[5] != srcp[5])
		return (dstp[5] - srcp[5]);
	if (dstp[6] != srcp[6])
		return (dstp[6] - srcp[6]);
	if (dstp[7] != srcp[7])
		return (dstp[7] - srcp[7]);
	return (0);
}

static int	memcmp_unalign(t_op dstp, t_op srcp, size_t len, size_t n_word)
{
	t_op			merge;
	const t_op		shift = srcp % 8;
	const size_t	shr = shift * 8;
	const size_t	shl = (8 - shift) * 8;

	srcp -= shift;
	while (n_word)
	{
		merge = *(t_op *)srcp >> shr | *(t_op *)(srcp + 1) << shl;
		if (*(t_op *)dstp != merge)
			return (nequiv_byte((t_byte *)dstp, (t_byte *)(srcp + shift)));
		dstp += 8;
		srcp += 8;
		n_word -= 1;
	}
	srcp += shift;
	while (len)
	{
		if (*(t_byte *)dstp != *(t_byte *)srcp)
			return (*(t_byte *)dstp - *(t_byte *)srcp);
		dstp += 1;
		srcp += 1;
		len -= 1;
	}
	return (0);
}

static int	memcmp_align(t_op dstp, t_op srcp, size_t len, size_t n_word)
{
	while (n_word)
	{
		if (*(t_op *)dstp != *(t_op *)srcp)
			return (nequiv_byte((t_byte *)dstp, (t_byte *)srcp));
		dstp += 8;
		srcp += 8;
		n_word -= 1;
	}
	while (len)
	{
		if (*(t_byte *)dstp != *(t_byte *)srcp)
			return (*(t_byte *)dstp - *(t_byte *)srcp);
		dstp += 1;
		srcp += 1;
		len -= 1;
	}
	return (0);
}

static int	memcmp_small(t_byte *dstp, t_byte *srcp, size_t len)
{
	while (len)
	{
		if (*dstp != *srcp)
			return (*dstp - *srcp);
		dstp += 1;
		srcp += 1;
		len -= 1;
	}
	return (0);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_op	srcp;
	t_op	dstp;
	int		r;

	if (n)
	{
		dstp = (t_op)s1;
		srcp = (t_op)s2;
		while (dstp % 8 != 0 && n)
		{
			if (*((t_byte *)dstp) != *((t_byte *)srcp))
				return (*((t_byte *)dstp) - *((t_byte *)srcp));
			dstp += 1;
			srcp += 1;
			n -= 1;
		}
		if (n > 7)
			r = (srcp % 8 == 0) ? memcmp_align(dstp, srcp, n % 8, n / 8) :
				memcmp_unalign(dstp, srcp, n % 8, n / 8);
		else
			r = memcmp_small((t_byte *)dstp, (t_byte *)srcp, n);
		return (r);
	}
	return (0);
}
