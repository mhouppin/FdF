/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 11:36:23 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 15:21:58 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mvalloc(void *ptr, size_t psize, size_t nsize)
{
	void	*nptr;

	if ((nptr = malloc(nsize)) == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(nptr, ptr, (psize < nsize) ? psize : nsize);
	free(ptr);
	return (nptr);
}
