/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 11:57:59 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:07:53 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "display.h"

static const char	*g_errtable[] =
{
	"Error: where's the file?",
	"Error: file doesn't contain a single number",
	"Error: a malloc failed",
	"Error: calm down on your height values!",
	"Error: unknown parameter on command-line",
	"Error: colorset shouldn't be zero-sized",
	"Error: invalid colorset parameter",
	"Error: mlx_init failed",
	"Error: window_init failed"
};

void	print_usage(char *filename)
{
	ft_putstr("\n usage: ");
	ft_putstr(filename);
	ft_putstr(" filename - \e[4mBuilds a wireframe"
			" from the filename content.\e[0m\n\n");
	ft_putstr("\t \"--colset=\e[1m0x00\e[31mRR\e[32mGG\e[34mBB\e[0;1m"
			" [\e[1m0x00\e[31mRR\e[32mGG\e[34mBB\e[0;1m ...]\e[0m\""
			" - modify the color set for grid\n");
	ft_putstr("\t \"--scale=\e[1m240\e[0m\" - Adjust height scale"
			" (by default, scale=100)\n\n");
	exit(0);
}

void	print_error(int errval)
{
	ft_putendl_fd(g_errtable[errval], 2);
	exit(-1);
}

void	assert_error(int condition, int errval)
{
	if (condition)
		print_error(errval);
}
