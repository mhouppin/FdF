/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:25:10 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 10:40:33 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	if ((new = ft_lstnew(f(lst)->content, f(lst)->content_size)) == NULL)
		return (NULL);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		if ((new->next = ft_lstnew(f(lst)->content, f(lst)->content_size))
				== NULL)
			return (NULL);
		new = new->next;
	}
	return (tmp);
}
