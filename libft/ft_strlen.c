/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 10:09:06 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 10:41:42 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_op	null_byte(t_byte *ptr)
{
	if (ptr[0] == 0)
		return (0);
	if (ptr[1] == 0)
		return (1);
	if (ptr[2] == 0)
		return (2);
	if (ptr[3] == 0)
		return (3);
	if (ptr[4] == 0)
		return (4);
	if (ptr[5] == 0)
		return (5);
	if (ptr[6] == 0)
		return (6);
	if (ptr[7] == 0)
		return (7);
	return (-1);
}

size_t		ft_strlen(const char *str)
{
	t_op	k;
	t_op	strp;

	strp = (t_op)str;
	if (*str == '\0')
		return (0);
	while (strp % 8 != 0)
	{
		if (*(t_byte *)strp == 0)
			return ((size_t)(strp - (t_op)str));
		strp += 1;
	}
	while (strp)
	{
		k = *(t_op *)strp;
		if ((k - 0x0101010101010101UL) & (~k) & 0x8080808080808080UL)
			return ((size_t)(strp + null_byte((t_byte *)strp) - (t_op)str));
		strp += 8;
	}
	return (-1);
}
