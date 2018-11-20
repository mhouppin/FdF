/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 10:57:52 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 11:15:43 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *ptr;

	ptr = ft_memchr(src, c, n);
	if (ptr == NULL)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	else
	{
		ft_memcpy(dst, src, ptr + 1 - src);
		return (dst + (size_t)ptr - (size_t)src + 1);
	}
}
