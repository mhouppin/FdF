/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 15:33:52 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 12:58:56 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*copy;
	const size_t	n = ft_strlen(s1) + 1;

	copy = (char*)malloc(n * sizeof(char));
	if (copy == NULL)
		return (NULL);
	return ((char*)ft_memcpy((void*)copy, (void*)s1, n));
}
