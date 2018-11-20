/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_list.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 09:39:40 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 09:46:36 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_node(t_list *lst)
{
	ft_print_mem(lst->content, lst->content_size);
	write(1, "\n\n", 2);
	ft_print_ptr(lst);
	write(1, " ->\n\n", 5);
}

void		ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_print_node(lst);
		lst = lst->next;
	}
}
