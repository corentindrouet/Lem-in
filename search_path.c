/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 09:16:52 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/23 16:33:27 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		search_i(t_salle *room, int i)
{
	int		j;

	j = -1;
	while (i)
	{
		if (room->hall[++j])
			i--;
	}
	return (j);
}

int		recur_path(t_stap *st, t_path **pat, t_salle **room, t_allp **pt)
{
	int		p;
	t_path	*t;

	add_path_end(pat, new_path((*room)->name));
	if ((p = verif_fin(room, st, pt)) != -1)
		return (p);
	t = (*pat)->next;
	(*room)->pass = 1;
	if (nb_valid_next(st, *room) == 1)
	{
		p = recur_path(st, &t, &((*room)->hall[s_i_valid(*room, 1, st)]), pt);
		if (!p)
		{
			free_path(&t);
			t->next = NULL;
		}
		(*room)->pass = 0;
		return (p);
	}
	return (multi_path(st, pat, room, pt));
}

t_allp	*opti_path(t_allp ***o)
{
	t_allp	*ret;
	int		max;
	int		i;

	i = -1;
	ret = (*o)[++i];
	max = allp_len((*o)[i]);
	while ((*o)[++i])
		if (max < allp_len((*o)[i]))
		{
			ret = (*o)[i];
			max = allp_len((*o)[i]);
		}
	return (ret);
}

int		search_all_path(t_stap st, t_allp **pat, t_salle **room)
{
//	int		t[5];
	int		i;
	int		j;
	int		k;
	int		lenroom;
	int		p;
	t_allp	*tmp;
	t_allp	**opti;

	lenroom = salle_len(*room);
	init_all_path(st, *room, &opti);
	ft_putnbr(lenroom);
	(*room)->pass = 1;
	j = -1;
	p = 0;
	while (++j < nb_next(&st, *room))
	{
		i = search_i(*room, j + 1);
		tmp = opti[j];
		k = (i - 1);
		while ((++k != (i - 1)) && tmp)
			if (k >= lenroom)
			{
				k = -1;
				i++;
			}
			else if ((*room)->hall[k])
			{
				if (!recur_path(&st, &(tmp->path),
					&((*room)->hall[k]), &opti[j]))
				{
					tmp = free_allp(&tmp, &opti, j);
				}
				else
				{
					verif_bouchon(&opti[j]);
					tmp = tmp->next;
					p++;
				}
			}
	}
	if (!p)
		return (0);
	*pat = opti_path(&opti);
	return (1);
}
