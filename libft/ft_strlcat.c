/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:34:18 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 11:16:12 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t len)
{
	size_t	l1;
	size_t	l2;

	l2 = ft_strlen(s2);
	l1 = 0;
	while (s1[l1])
	{
		if (l1 == len)
			return (l1 + l2);
		l1++;
	}
	if (l1 + 1 == len || l1 == len)
		return (l1 + l2);
	s1 += l1;
	len -= l1;
	while (*s2 != 0 && len-- > 1)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (l1 + l2);
}
