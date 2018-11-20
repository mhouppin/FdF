/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:05:06 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:12:04 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	no_blk_end(const char *s)
{
	int i;

	if (!s)
		return (0);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i + 1);
}

static size_t	no_blk_start(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char			*ft_strtrim(const char *s)
{
	const size_t	start = no_blk_start(s);
	const size_t	end = no_blk_end(s);
	size_t			i;
	char			*new;

	if (!s)
		return (NULL);
	if (end <= start)
	{
		if ((new = (char*)malloc(sizeof(char))) == NULL)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if ((new = (char*)malloc(sizeof(char) * (end - start + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
