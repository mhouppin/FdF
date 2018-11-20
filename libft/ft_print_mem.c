/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_mem.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:00:50 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:40:56 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putspec(unsigned char c)
{
	if (c > 31 && c < 127)
		ft_putchar(c);
	else
		ft_putchar('.');
}

static void	print_hex(unsigned char c)
{
	const unsigned char a = c / 16;
	const unsigned char b = c % 16;

	if (a < 10)
		ft_putchar(a + '0');
	else
		ft_putchar(a + 'a' - 10);
	if (b < 10)
		ft_putchar(b + '0');
	else
		ft_putchar(b + 'a' - 10);
}

static void	disp_hex(const void *addr, size_t size, size_t line)
{
	int		block;
	int		digit;
	size_t	decal;

	block = -1;
	while (++block < 8)
	{
		digit = -1;
		while (++digit < 2)
		{
			if ((decal = 16 * line + 2 * block + digit) < size)
				print_hex(*(char*)(addr + decal));
			else
				write(1, "  ", 2);
		}
		ft_putchar(' ');
	}
}

static void	disp_char(const void *addr, size_t size, size_t line)
{
	int		block;
	int		digit;
	size_t	decal;

	block = -1;
	while (++block < 8)
	{
		digit = -1;
		while (++digit < 2)
			if ((decal = 16 * line + 2 * block + digit) < size)
				ft_putspec(*(char*)(addr + decal));
	}
	ft_putchar('\n');
}

void		ft_print_mem(const void *addr, size_t size)
{
	const size_t	resize = (((size - 1) / 16) + 1) * 16;
	size_t			line;

	line = 0;
	while (16 * line < resize)
	{
		disp_hex(addr, size, line);
		disp_char(addr, size, line);
		line++;
	}
}
