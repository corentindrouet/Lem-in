/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 08:24:58 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/17 10:55:23 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reinit_nb_hall(t_allp **all_path)
{
	t_allp	*tmp;

	tmp = *all_path;
	while (tmp)
	{
		tmp->nb_hall = path_len(tmp->path);
		tmp = tmp->next;
	}
}

int		compar_path(t_path *p1, t_path *p2)
{
	t_path	*tmp;

	p1 = p1->next;
	while (p1)
	{
		tmp = p2->next;
		while (tmp && tmp->next)
		{
			if (!ft_strcmp(p1->name, tmp->name))
				return (0);
			tmp = tmp->next;
		}
		p1 = p1->next;
	}
	return (1);
}

t_allp	*free_p(t_allp **elem)
{
	t_path	*tmp;
	t_allp	*ne;

	tmp = (*elem)->path;
	while (tmp)
	{
		(*elem)->path = (*elem)->path->next;
		free(tmp->name);
		free(tmp);
		tmp = (*elem)->path;
	}
	ne = (*elem)->next;
	free(*elem);
	return (ne);
}

void	free_elem(t_allp **al, t_allp *elem)
{
	t_allp	*tmp;

	tmp = *al;
	while (tmp)
	{
		if (tmp->next == elem)
		{
			tmp->next = free_p(&(tmp->next));
			break ;
		}
		tmp = tmp->next;
	}
}

void	verif_bouchon(t_allp **all_path)
{
	t_allp	*tmp_i;
	t_allp	*tmp_j;

	tmp_i = (*all_path);
	while (tmp_i)
	{
		tmp_j = tmp_i->next;
		while (tmp_j)
		{
			if (!compar_path(tmp_i->path, tmp_j->path))
				free_elem(all_path, (tmp_i->nb_hall > tmp_j->nb_hall) ? tmp_i : tmp_j);
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}
