/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:25:23 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/17 11:38:23 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		verif_tri(t_allp *p)
{
	while (p->next)
	{
		if (p->nb_hall > p->next->nb_hall)
			return (0);
		p = p->next;
	}
	return (1);
}

void	tri_path(t_allp **p)
{
	t_allp	*tmp;
	t_path	*t;

	tmp = *p;
	while (!verif_tri(*p))
	{
		while (tmp->next)
		{
			if (tmp->nb_hall > tmp->next->nb_hall)
			{
				t = tmp->path;
				tmp->path = tmp->next->path;
				tmp->next->path = t;
				tmp->nb_hall = path_len(tmp->path);
				tmp->next->nb_hall = path_len(tmp->next->path);
			}
			tmp = tmp->next;
		}
	}
}
