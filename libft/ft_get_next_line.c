/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 11:28:41 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 11:34:18 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strcut(char *buffer, char **line, char *excess)
{
	char	*too_much;
	char	*tmp;
	char	*tmp2;

	too_much = ft_strchr(buffer, '\n');
	tmp = ft_strnew((size_t)(too_much - buffer));
	ft_memcpy(tmp, buffer, (size_t)(too_much - buffer));
	tmp2 = ft_strjoin(*line, tmp);
	free(*line);
	*line = tmp2;
	free(tmp);
	ft_memcpy(excess, too_much + 1,
			(size_t)(BUFF_SIZE - (size_t)too_much + (size_t)buffer));
	free(buffer);
}

static int		get_line(const int fd, char **line, char *excess, char *buffer)
{
	char	*tmp;
	int		rbytes;

	while ((rbytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rbytes] = '\0';
		if (ft_strchr(buffer, '\n') == NULL)
		{
			tmp = ft_strjoin(*line, buffer);
			free(*line);
			*line = tmp;
		}
		else
		{
			ft_strcut(buffer, line, excess);
			return (1);
		}
	}
	free(buffer);
	return (**line != '\0');
}

static void		move_bytes(char *str, int len)
{
	int i;

	i = 0;
	while (str[i + len] != '\0')
	{
		str[i] = str[i + len];
		i++;
	}
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}

inline int		ft_get_next_line(const int fd, char **line)
{
	static char	*excess = NULL;
	char		*buffer;

	if (!line || read(fd, NULL, 0) == -1)
		return (-1);
	excess = (!excess) ? ft_strnew(BUFF_SIZE) : excess;
	if (*excess != '\0' && ft_strchr(excess, '\n') == NULL)
	{
		*line = ft_strdup(excess);
		ft_strclr(excess);
	}
	else if (*excess != '\0')
	{
		*line = ft_strsub(excess, 0,
				(int)(ft_strchr(excess, '\n') - excess));
		move_bytes(excess, (int)(ft_strchr(excess, '\n') - excess + 1));
		return (1);
	}
	else
		*line = ft_strnew(0);
	buffer = ft_strnew(BUFF_SIZE);
	return (get_line(fd, line, excess, buffer));
}
