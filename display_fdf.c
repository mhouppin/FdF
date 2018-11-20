/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_fdf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 15:17:49 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:07:02 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_fdfinfo *info)
{
	int	t;

	assert_error(!(info->mlxptr = mlx_init()), INIT_FAIL);
	info->winptr = mlx_new_window(info->mlxptr, WIN_X, WIN_Y, "FdF");
	assert_error(!(info->winptr), WIN_FAIL);
	info->imgptr = mlx_new_image(info->mlxptr, WIN_X, WIN_Y);
	assert_error(!(info->imgptr), MALLOC_FAIL);
	info->image = mlx_get_data_addr(info->imgptr, &t, &t, &t);
	assert_error(!(info->image), WIN_FAIL);
	info->xpos = 0;
	info->ypos = 0;
	info->zoom = ((double)WIN_X / (info->x - 1) / 2 <
			(double)WIN_Y / (info->y - 1) / 2) ?
		(double)WIN_X / (info->x - 1) / 2 : (double)WIN_Y / (info->y - 1) / 2;
	info->zoom_init = info->zoom;
}

/*
** xa = (WIN_X / 2.0) + (p.x + xpos - (x - 1) / 2) * zoom
**		- (p.y + ypos - (y - 1) / 2) * zoom
** ya = (WIN_Y / 2.0) - (p.x + xpos - (x - 1) / 2) * zoom
**		- (p.y + ypos - (y - 1) / 2) * zoom
**
** WIN_X = 720, WIN_Y = 720
** xmove = 0;
** ymove = 0;
** x = 3;
** y = 3;
** p.x = 0;
** p.y = 1;
** zoom = (WIN_X / (x - 1) / 2) = 180;
**
** xa0 = (720 / 2.0) + (0 + 0 - 3 / 2) * 240 - (0 + 0 - 3 / 2) * 240
** xa0 = 360 + (-1.5) * 240 - (-1.5) * 240
** xa0 = 360
** ya0 = (720 / 2.0) - (0 + 0 - 3 / 2) * 240 - (0 + 0 - 3 / 2) * 240
** ya0 = 360 - (-1.5) * 240 - (-1.5) * 240
** ya0 = 1080
*/

void	draw_line(int height_a, int height_b, t_position p, t_fdfinfo *info)
{
	t_position	a;
	t_position	b;

	a.x = ((double)WIN_X / 2.0) +
		((double)p.x + info->xpos - (double)(info->x - 1) / 2.0) * info->zoom -
		((double)p.y + info->ypos - (double)(info->y - 1) / 2.0) * info->zoom;
	a.y = ((double)WIN_Y / 2.0) -
		((double)p.x + info->xpos - (double)(info->x - 1) / 2.0) * info->zoom -
		((double)p.y + info->ypos - (double)(info->y - 1) / 2.0) * info->zoom;
	b.x = ((double)WIN_X / 2.0) +
		((double)p.x + info->xpos - (double)(info->x - 3) / 2.0) * info->zoom -
		((double)p.y + info->ypos - (double)(info->y - 1) / 2.0) * info->zoom;
	b.y = ((double)WIN_Y / 2.0) -
		((double)p.x + info->xpos - (double)(info->x - 3) / 2.0) * info->zoom -
		((double)p.y + info->ypos - (double)(info->y - 1) / 2.0) * info->zoom;
	a.y += (double)(height_a - info->hmin) /
		(double)(info->hmax - info->hmin) * info->zoom * info->scale;
	b.y += (double)(height_b - info->hmin) /
		(double)(info->hmax - info->hmin) * info->zoom * info->scale;
	a.y = WIN_Y - a.y;
	b.y = WIN_Y - b.y;
	if ((a.x < 0 && b.x < 0) || (a.y < 0 && b.y < 0) ||
			(a.x > WIN_X && b.x > WIN_X) || (a.y > WIN_Y && b.y > WIN_Y))
		return ;
	draw(height_var(height_a, height_b), a, b, info);
}

void	draw_column(int height_a, int height_b, t_position p, t_fdfinfo *info)
{
	t_position	a;
	t_position	b;

	a.x = ((double)WIN_X / 2.0) +
		((double)p.x + info->xpos - (double)(info->x - 1) / 2.0) * info->zoom -
		((double)p.y + info->ypos - (double)(info->y - 1) / 2.0) * info->zoom;
	a.y = ((double)WIN_Y / 2.0) -
		((double)p.x + info->xpos - (double)(info->x - 1) / 2.0) * info->zoom -
		((double)p.y + info->ypos - (double)(info->y - 1) / 2.0) * info->zoom;
	b.x = ((double)WIN_X / 2.0) +
		((double)p.x + info->xpos - (double)(info->x - 1) / 2.0) * info->zoom -
		((double)p.y + info->ypos - (double)(info->y - 3) / 2.0) * info->zoom;
	b.y = ((double)WIN_Y / 2.0) -
		((double)p.x + info->xpos - (double)(info->x - 1) / 2.0) * info->zoom -
		((double)p.y + info->ypos - (double)(info->y - 3) / 2.0) * info->zoom;
	a.y += (double)(height_a - info->hmin) /
		(double)(info->hmax - info->hmin) * info->zoom * info->scale;
	b.y += (double)(height_b - info->hmin) /
		(double)(info->hmax - info->hmin) * info->zoom * info->scale;
	a.y = WIN_Y - a.y;
	b.y = WIN_Y - b.y;
	if ((a.x < 0 && b.x < 0) || (a.y < 0 && b.y < 0) ||
			(a.x > WIN_X && b.x > WIN_X) || (a.y > WIN_Y && b.y > WIN_Y))
		return ;
	draw(height_var(height_a, height_b), a, b, info);
}

void	draw_grid(t_fdfinfo *info, int **grid)
{
	t_position	p;

	assert_error(info->x <= 1 || info->y <= 1, NO_NUMBER);
	p.x = 0;
	while (p.x < info->x)
	{
		p.y = 0;
		while (p.y < info->y)
		{
			if (p.x != info->x - 1)
				draw_line(grid[p.y][p.x], grid[p.y][p.x + 1], p, info);
			if (p.y != info->y - 1)
				draw_column(grid[p.y][p.x], grid[p.y + 1][p.x], p, info);
			p.y++;
		}
		p.x++;
	}
	mlx_put_image_to_window(info->mlxptr, info->winptr, info->imgptr, 0, 0);
}

void	display_fdf(int **grid, t_fdfinfo *info)
{
	t_dblptr	params;

	params.fdfinfo = info;
	params.grid_ptr = grid;
	init_window(info);
	draw_grid(info, grid);
	mlx_key_hook(info->winptr, &key_hook, &params);
	mlx_loop(info->mlxptr);
}
