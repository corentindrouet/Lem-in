/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 09:16:52 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/22 13:44:48 by cdrouet          ###   ########.fr       */
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
	int		i;
	int		p;
	t_path	**tmp;
	t_path	*t;

	i = nb_next(st, *room);
	add_path_end(pat, new_path((*room)->name));
	t = (*pat)->next;
	if ((p = verif_fin(room, st, pt)) != -1)
		return (p);
	tmp = (t_path**)malloc(sizeof(t_path*) * (i + 1));
	while (i >= 0)
		tmp[i--] = NULL;
	(*room)->pass = 1;
	if (nb_next(st, *room) == 1)
	{
		i = recur_path(st, &t, &((*room)->hall[search_i(*room, 1)]), pt);
		(*room)->pass = 0;
		return (i);
	}
	p = 0;
	i = -1;
	while (++i < st->nb_room)
		if ((*room)->hall[i] && !(*room)->hall[i]->pass)
		{
			if (recur_path(st, &t, &((*room)->hall[i]), pt))
				tmp[p++] = t->next;
			else
				free_path(&t);
			t->next = NULL;
		}
	(*room)->pass = 0;
	if (tmp[0] == NULL)
		return (0);
	t->next = tmp[search_index_low_path(tmp)];
	return (1);
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
	int		i;
	int		j;
	int		k;
	int		lenroom;
	int		nb_path;
	int		p;
	t_allp	*tmp;
	t_allp	**opti;

	i = -1;
	lenroom = salle_len(*room);
	nb_path = 0;
	while (++i < lenroom)
	{
		if ((*room)->hall[i])
		{
			if (!strcmp((*room)->flag, "start"))
				add_allp_end(pat, new_allp(new_path((*room)->name)));
			nb_path++;
		}
	}
	opti = (t_allp**)malloc(sizeof(t_allp*) * (nb_path + 1));
	i = -1;
	while (++i < nb_path)
	{
		j = -1;
		while (++j < lenroom)
			if ((*room)->hall[j])
				if (!strcmp((*room)->flag, "start"))
					add_allp_end(&opti[i], new_allp(new_path((*room)->name)));
	}
	opti[i] = NULL;
	(*room)->pass = 1;
	j = -1;
	p = 0;
	while (++j < nb_path)
	{
		i = search_i(*room, j + 1);
		tmp = opti[j];
		k = i - 1;
		while (++k != (i - 1) && tmp)
		{
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
					tmp = free_allp(&tmp, &opti[j]);
				}
				else
				{
					verif_bouchon(&opti[j]);
					tmp = tmp->next;
					p++;
				}
			}
		}
	}
	if (!p)
		return (0);
	*pat = opti_path(&opti);
	return (1);
}
