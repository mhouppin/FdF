/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:15:04 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 12:08:12 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*data;
	size_t	i;

	if ((data = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		data[i] = '\0';
		i++;
	}
	return (data);
}
