/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 09:16:52 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/24 10:16:39 by cdrouet          ###   ########.fr       */
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
	int		t[4];
	t_allp	*tmp;
	t_allp	**opti;

	opti = init_all_path(st, room, t);
	while (++t[1] < nb_next(&st, *room))
	{
		t[0] = search_i(*room, t[1] + 1);
		tmp = opti[t[1]];
		t[2] = (t[0] - 1);
		while ((++t[2] != (t[0] - 1)) && tmp)
			if (t[2] >= st.nb_room)
				end_room_hall(t);
			else if ((*room)->hall[t[2]])
			{
				if (!recur_path(&st, &(tmp->path),
					&((*room)->hall[t[2]]), &opti[t[1]]))
					tmp = free_allp(&tmp, &opti, t[1]);
				else
					recur_ok(&opti[t[1]], &tmp, &t[3]);
			}
	}
	*pat = opti_path(&opti);
	return ((!t[3]) ? 0 : 1);
}
