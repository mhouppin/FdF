/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:47:24 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:36:04 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (len == 0)
		return (NULL);
	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && (int)i < (int)len - (int)ft_strlen(needle)
			+ 1)
	{
		if (ft_isin((haystack + i), needle) == 1)
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
