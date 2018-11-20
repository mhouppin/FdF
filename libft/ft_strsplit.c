/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:12:25 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:59:31 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strndup(const char *s, size_t len)
{
	char *dup;

	dup = (char*)malloc(sizeof(char) * len);
	if (dup == NULL)
		return (NULL);
	if (ft_strncpy(dup, s, len - 1) == NULL)
	{
		free(dup);
		return (NULL);
	}
	dup[len - 1] = 0;
	return (dup);
}

static int			count_words(const char *s, char c)
{
	int count;

	count = 1;
	while (*s)
	{
		if (*s && *s == c)
		{
			count++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char			*get_wordcpy(const char *s, char c)
{
	int		length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (ft_strndup(s, length + 1));
}

static int			copy_words(char **split, const char *trim, char c)
{
	if ((*(split++) = get_wordcpy(trim, c)) == NULL)
		return (0);
	while (*trim)
	{
		if (*trim == c)
		{
			while (*trim == c)
				trim++;
			if ((*(split++) = get_wordcpy(trim, c)) == NULL)
				return (0);
		}
		else
			trim++;
	}
	*split = NULL;
	return (1);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**split;
	char	*trim;
	int		words_count;

	if (!s)
		return (NULL);
	if ((trim = ft_strtrim_c(s, c)) == NULL)
		return (NULL);
	if (*trim == '\0')
	{
		if (!(split = (char**)malloc(sizeof(char*))))
			return (NULL);
		*split = NULL;
		return (split);
	}
	words_count = count_words(trim, c);
	if (!(split = (char**)malloc(sizeof(char*) * (words_count + 1))))
	{
		free(trim);
		return (NULL);
	}
	if (copy_words(split, trim, c) == 0)
		return (NULL);
	free(trim);
	return (split);
}
