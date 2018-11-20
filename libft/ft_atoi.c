/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:10:57 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 10:34:49 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	result;
	int		neg;
	char	*s;

	s = (char*)str;
	result = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\r'
			|| *s == '\f' || *s == '\v')
		s += 1;
	neg = (*s == '-') ? -1 : 1;
	s += (*s == '-' || *s == '+') ? 1 : 0;
	while (*s > '0' - 1 && *s < '9' + 1)
	{
		result = result * 10 + *s - '0';
		s += 1;
	}
	return (result * neg);
}