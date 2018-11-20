/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 15:46:48 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:06:19 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		set_box(t_fdfinfo *info, double xmove, double ymove, double zoomset)
{
	info->xpos += xmove;
	info->ypos += ymove;
	info->zoom *= zoomset;
	return (0);
}

int		key_hook(int keycode, void *fdfptr)
{
	t_fdfinfo	*info;
	int			**grid;

	info = ((t_dblptr *)fdfptr)->fdfinfo;
	grid = ((t_dblptr *)fdfptr)->grid_ptr;
	if (keycode == 126)
		set_box(info, 10 / info->zoom, 10 / info->zoom, 1);
	if (keycode == 123)
		set_box(info, 10 / info->zoom, -10 / info->zoom, 1);
	if (keycode == 124)
		set_box(info, -10 / info->zoom, 10 / info->zoom, 1);
	if (keycode == 125)
		set_box(info, -10 / info->zoom, -10 / info->zoom, 1);
	(keycode == 69 || keycode == 24) ? set_box(info, 0, 0, 1.25) : 0;
	(keycode == 78 || keycode == 27) ? set_box(info, 0, 0, 0.8) : 0;
	if (keycode == 1)
	{
		info->zoom = info->zoom_init;
		info->xpos = 0;
		info->ypos = 0;
	}
	(keycode == 53) ? exit(0) : 0;
	ft_bzero(info->image, WIN_X * WIN_Y * 4);
	draw_grid(info, grid);
	return (0);
}
