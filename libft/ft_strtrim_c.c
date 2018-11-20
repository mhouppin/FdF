/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim_c.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 09:42:20 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:11:56 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	no_c_end(const char *s, char c)
{
	int i;

	if (!s)
		return (0);
	i = ft_strlen(s) - 1;
	while (s[i] == c && i > -1)
		i--;
	return (i + 1);
}

static size_t	no_c_start(const char *s, char c)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

char			*ft_strtrim_c(const char *s, char c)
{
	const size_t	start = no_c_start(s, c);
	const size_t	end = no_c_end(s, c);
	size_t			i;
	char			*new;

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
