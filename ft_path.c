/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 08:39:34 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/24 10:12:41 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_allp_end(t_allp **lst, t_allp *new)
{
	t_allp	*tmp;

	tmp = *lst;
	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	destroy_last_path(t_path **p)
{
	free((*p)->next->name);
	free((*p)->next);
	(*p)->next = NULL;
}

void	free_path(t_path **p)
{
	if (!(*p))
		return ;
	if ((*p)->next)
	{
		free((*p)->next->name);
		free((*p)->next);
	}
}

t_allp	*free_allp(t_allp **p, t_allp ***start, int j)
{
	t_allp	*tmp;
	t_allp	**par;

	par = (*start);
	if (par[j] == (*p))
	{
		tmp = (*p)->next;
		free(*p);
		par[j] = tmp;
		return (tmp);
	}
	while (par[j]->next != (*p) && par[j]->next)
		par[j] = par[j]->next;
	tmp = par[j]->next;
	if (par[j]->next)
		par[j]->next = par[j]->next->next;
	free(tmp);
	return (par[j]->next);
}

t_allp	*new_allp(t_path *p)
{
	t_allp	*lst;

	lst = (t_allp*)malloc(sizeof(t_allp));
	lst->path = p;
	lst->nb_hall = 1;
	lst->next = NULL;
	return (lst);
}
