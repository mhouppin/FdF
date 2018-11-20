/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 14:46:55 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 10:47:19 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (dst > src && dst < (src + len))
	{
		i = len - 1;
		while (i != 0)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i--;
		}
		*(char*)dst = *(char*)src;
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
