/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 09:04:56 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:07:32 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

#define T_1		255U
#define T_2		65535U
#define T_3		16777215U
#define T_4		4294967295U

int			colval(int height, t_fdfinfo *info)
{
	double	hd;
	t_argb	argb;
	t_argb	start;
	t_argb	end;
	int		icol;

	hd = (double)(info->hmax - info->hmin) / (info->colors - 1);
	icol = 0;
	while ((double)info->hmin + hd * (icol + 1) < height &&
			icol < info->colors - 1)
		icol++;
	if (icol == info->colors - 1)
		return (info->colshade[icol]);
	start.i = info->colshade[icol];
	end.i = info->colshade[icol + 1];
	hd = (height - info->hmin - hd * icol) / hd;
	argb.r[0] = start.r[0] + (double)(end.r[0] - start.r[0]) * hd;
	argb.r[1] = start.r[1] + (double)(end.r[1] - start.r[1]) * hd;
	argb.r[2] = start.r[2] + (double)(end.r[2] - start.r[2]) * hd;
	argb.r[3] = start.r[3] + (double)(end.r[3] - start.r[3]) * hd;
	return (argb.i);
}

t_position	height_var(int a, int b)
{
	t_position p;

	p.x = a;
	p.y = b;
	return (p);
}

void		draw(t_position hvar, t_position a, t_position b, t_fdfinfo *info)
{
	int			p;
	t_position	i;
	double		dx;
	double		dy;
	t_position	z;

	p = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	dx = (double)(b.x - a.x) / (double)p;
	dy = (double)(b.y - a.y) / (double)p;
	i.x = 0;
	while (i.x < p)
	{
		i.y = colval(hvar.x + (hvar.y - hvar.x) * i.x / p, info);
		z.x = a.x + (int)(dx * (double)i.x);
		z.y = a.y + (int)(dy * (double)i.x);
		if (z.x >= 0 && z.x < WIN_X && z.y >= 0 && z.y < WIN_Y)
			((int*)(info->image))[z.x + z.y * WIN_X] = i.y;
		i.x++;
	}
}
