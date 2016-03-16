/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 08:39:34 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/16 08:58:57 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_allp_end(t_allp **lst, t_allp *new)
{
	if (!(*lst))
		(*lst) = new;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
	}
}

int		path_len(t_path *p)
{
	int	i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

t_allp	*new_allp(t_path *p)
{
	t_allp	*lst;

	lst = (t_allp*)malloc(sizeof(t_allp));
	lst->path = p;
	lst->nb_hall = path_len(p);
	return (lst);
}
