/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:37:27 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 15:54:02 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t			i;
	const size_t	len = ft_strlen(haystack);
	void			*ptr;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (i < len)
	{
		ptr = ft_memchr((void*)(haystack + i), (int)(*needle), len - i);
		i = (ptr == NULL) ? len : (size_t)(ptr - (void*)haystack);
		if (ft_isin((haystack + i), needle) == 1)
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
