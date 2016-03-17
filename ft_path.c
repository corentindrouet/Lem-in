/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 08:39:34 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/17 08:46:16 by cdrouet          ###   ########.fr       */
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

t_allp	*free_allp(t_allp **p, t_allp **start)
{
	t_allp	*tmp;
	t_allp	*par;

	par = *start;
	if (par == (*p))
	{
		tmp = (*p)->next;
		free(*p);
		return (tmp);
	}
	while (par->next != (*p) && par->next)
		par = par->next;
	tmp = par->next;
	if (par->next)
		par->next = par->next->next;
	free(tmp);
	return (par->next);
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
	lst->nb_hall = 1;
	lst->next = NULL;
	return (lst);
}
