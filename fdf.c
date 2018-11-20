/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 13:17:36 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:06:43 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		*big_atoi(char **splitted, int size, t_fdfinfo *info)
{
	int	*result;
	int	i;

	result = (int*)malloc(sizeof(int) * size);
	assert_error(result == NULL, MALLOC_FAIL);
	i = 0;
	while (i < size)
	{
		result[i] = ft_atoi(splitted[i]);
		info->hmax = (info->hmax < result[i]) ? result[i] : info->hmax;
		info->hmin = (info->hmin > result[i]) ? result[i] : info->hmin;
		i++;
	}
	return (result);
}

void	free_tab(char **tab)
{
	char **tmp;

	tmp = tab;
	while (*tab != NULL)
	{
		free(*tab);
		tab++;
	}
	free(tmp);
}

int		tabsize(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	fdf(t_fdfinfo *info, char *filename)
{
	int			fd;
	int			**grid;
	t_digest	data;
	int			int_count;

	info->y = 0;
	info->x = 2147483647;
	info->hmax = -2147483648;
	info->hmin = 2147483647;
	assert_error(!(grid = (int**)ft_memalloc(sizeof(int*))), MALLOC_FAIL);
	assert_error((fd = open(filename, O_RDONLY)) == -1, NO_FILE);
	while (ft_get_next_line(fd, &(data.line)) == 1)
	{
		data.splitted = ft_strsplit(data.line, ' ');
		int_count = tabsize(data.splitted);
		info->x = (info->x < int_count) ? info->x : int_count;
		assert_error(data.splitted == NULL, MALLOC_FAIL);
		free(data.line);
		grid = (int**)ft_mvalloc(grid, 8 * (++info->y), 8 * info->y + 8);
		assert_error(grid == NULL, MALLOC_FAIL);
		grid[info->y - 1] = big_atoi(data.splitted, int_count, info);
		free_tab(data.splitted);
	}
	close(fd);
	display_fdf(grid, info);
}
