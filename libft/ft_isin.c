/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isin.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 10:23:56 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 10:31:33 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isin(const char *srch, const char *ref)
{
	size_t	i;

	i = 0;
	while (ref[i] != '\0')
	{
		if (srch[i] != ref[i])
			return (0);
		i++;
	}
	return (1);
}
