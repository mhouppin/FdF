/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 10:13:31 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:12:09 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "display.h"
# include <math.h>
# include <fcntl.h>

# define WIN_X	1440
# define WIN_Y	1440

typedef struct	s_fdfinfo
{
	int		colors;
	int		*colshade;
	int		hmax;
	int		hmin;
	double	scale;
	int		x;
	int		y;
	void	*mlxptr;
	void	*winptr;
	double	xpos;
	double	ypos;
	double	zoom;
	double	zoom_init;
	char	*imgptr;
	void	*image;
}				t_fdfinfo;

typedef struct	s_digest
{
	char	*line;
	char	**splitted;
}				t_digest;

typedef struct	s_dblptr
{
	t_fdfinfo	*fdfinfo;
	int			**grid_ptr;
}				t_dblptr;

typedef struct	s_position
{
	int			x;
	int			y;
}				t_position;

typedef union	u_argb
{
	unsigned int	i;
	unsigned char	r[4];
}				t_argb;

void			fdf(t_fdfinfo *info, char *filename);

void			display_fdf(int **grid, t_fdfinfo *info);

t_position		height_var(int a, int b);

void			draw
(t_position hvar, t_position a, t_position b, t_fdfinfo *info);

void			draw_grid(t_fdfinfo *info, int **grid);

int				key_hook(int keycode, void *fdfptr);

#endif
