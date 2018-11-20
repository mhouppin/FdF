/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:56:17 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 12:05:47 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*data;
	size_t	i;

	if ((data = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(char*)(data + i) = 0;
		i++;
	}
	return (data);
}
