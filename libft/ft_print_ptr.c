/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_ptr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 09:46:42 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 09:20:34 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_hex(unsigned long l)
{
	char c;

	if (l < 10)
	{
		c = l + '0';
		ft_putchar(c);
	}
	else if (l < 16)
	{
		c = l + 'a' - 10;
		ft_putchar(c);
	}
	else
	{
		ft_print_hex(l / 16);
		ft_print_hex(l % 16);
	}
}

void		ft_print_ptr(void *ptr)
{
	ft_putstr("0x");
	ft_print_hex((unsigned long)ptr);
}
