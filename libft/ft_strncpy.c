/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:21:19 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 09:12:55 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	const size_t	n = ft_strlen(src) + 1;
	const size_t	i = (n < len + 1) ? n : len;

	ft_memcpy((void*)dst, (void*)src, i);
	ft_bzero((void*)(dst + i), len - i);
	return (dst);
}
