/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 12:57:25 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 13:12:59 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	set_big_packs(long int dst, t_op k, size_t len)
{
	while (len > 0)
	{
		((t_op *)dst)[0] = k;
		((t_op *)dst)[1] = k;
		((t_op *)dst)[2] = k;
		((t_op *)dst)[3] = k;
		((t_op *)dst)[4] = k;
		((t_op *)dst)[5] = k;
		((t_op *)dst)[6] = k;
		((t_op *)dst)[7] = k;
		dst += 8 * OPSIZE;
		len--;
	}
}

static void	set_packs(long int dst, t_op k, size_t len)
{
	while (len > 0)
	{
		((t_op *)dst)[0] = k;
		dst += OPSIZE;
		len--;
	}
}

static t_op	ccopy(t_byte c)
{
	t_op k;

	k = c;
	k |= k << 8;
	k |= k << 16;
	k |= k << 32;
	return (k);
}

void		*ft_memset(void *dst, int c, size_t len)
{
	const t_op	k = ccopy((t_byte)c);
	long int	dstp;

	dstp = (long int)dst;
	if (len >= 8)
	{
		while (dstp % OPSIZE != 0)
		{
			((t_byte *)dstp)[0] = c;
			dstp += 1;
			len -= 1;
		}
		set_big_packs(dstp, k, len / (OPSIZE * 8));
		dstp += (len / (OPSIZE * 8)) * OPSIZE * 8;
		len %= 8 * OPSIZE;
		set_packs(dstp, k, len / OPSIZE);
		dstp += (len / OPSIZE) * OPSIZE;
		len %= OPSIZE;
	}
	while (len > 0)
	{
		((t_byte *)dstp++)[0] = c;
		len -= 1;
	}
	return (dst);
}
