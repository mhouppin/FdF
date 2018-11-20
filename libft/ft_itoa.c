/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:07:31 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 09:09:21 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t count;

	if (n == -2147483648)
		return (11);
	count = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*new;
	size_t	i;
	long	l;

	l = (long)n;
	if (l == 0)
	{
		if ((new = ft_strdup("0")) == NULL)
			return (NULL);
		return (new);
	}
	if ((new = (char*)malloc(ft_nbrlen(n) + 1)) == NULL)
		return (NULL);
	i = ft_nbrlen(n) - 1;
	new[i + 1] = '\0';
	if (n < 0)
		new[0] = '-';
	l = (l < 0) ? -l : l;
	while (l != 0)
	{
		new[i] = (l % 10) + '0';
		l /= 10;
		i--;
	}
	return (new);
}
