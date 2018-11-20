/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 11:54:16 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 11:58:12 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		atohex(const char *str)
{
	unsigned int result;

	result = 0;
	assert_error(!ft_isin(str, "0x"), COLSET_INV);
	str += 2;
	while (*str && *str != ' ')
	{
		assert_error(!(ft_isdigit(*str) || (*str >= 'a' && *str <= 'f') ||
					(*str >= 'A' && *str <= 'F')), COLSET_INV);
		assert_error(result >= 268435456, COLSET_INV);
		result *= 16;
		result += (*str >= '0' && *str <= '9') ? *str - '0' : 0;
		result += (*str >= 'a' && *str <= 'f') ? *str - 'a' + 10 : 0;
		result += (*str >= 'A' && *str <= 'F') ? *str - 'A' + 10 : 0;
		str++;
	}
	return (result);
}

void	get_colset(t_fdfinfo *info, const char *str)
{
	int	i;

	str += 9;
	info->colors = (ft_strlen(str) + 1) / 11;
	assert_error(info->colors == 0, COLSET_ZERO);
	if (!(info->colshade = (int*)malloc(sizeof(int) * info->colors)))
		print_error(MALLOC_FAIL);
	i = 0;
	while (i < info->colors)
	{
		info->colshade[i] = atohex(str);
		i++;
		str += 11;
	}
}

int		main(int argc, char **argv)
{
	int			i;
	t_fdfinfo	info;

	info.colors = 0;
	info.scale = 1.5;
	(argc == 1) ? print_usage(argv[0]) : 0;
	i = 1;
	while (i < argc - 1)
	{
		if (ft_isin(argv[i], "--colset="))
			get_colset(&info, argv[i]);
		else if (ft_isin(argv[i], "--scale="))
			info.scale = (double)ft_atoi(argv[i] + 8) * 0.015;
		else
			print_error(UNKNOWN_PARAM);
		i++;
	}
	if (info.colors == 0)
		get_colset(&info, "--colset=0x00FF0000 0x00FFFF00 0x00FFFFFF");
	fdf(&info, argv[argc - 1]);
	return (0);
}
