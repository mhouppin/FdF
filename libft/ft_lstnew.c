/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:04:22 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:15:10 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((new->content = malloc(content_size)) == NULL && content_size != 0)
	{
		free(new);
		return (NULL);
	}
	if (content)
		ft_memcpy(new->content, content, content_size);
	else
		new->content = NULL;
	new->content_size = ((!content) ? 0 : content_size);
	new->next = NULL;
	return (new);
}
