/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:24:49 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/23 12:03:30 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		nb_valid_next(t_stap *st, t_salle *room)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (i < st->nb_room)
	{
		if (room->hall[i] && !room->hall[i]->pass)
			p++;
		i++;
	}
	return (p);
}

int		s_i_valid(t_salle *room, int i, t_stap *st)
{
	int		j;

	j = -1;
	while (i && (j + 1) < st->nb_room)
	{
		if (room->hall[++j] && !room->hall[j]->pass)
			i--;
	}
	return (j);
}

int		multi_path(t_stap *st, t_path **pat, t_salle **room, t_allp **pt)
{
	int		p;
	int		i;
	t_path	**tmp;
	t_path	*t;

	t = (*pat)->next;
	i = nb_valid_next(st, *room);
	tmp = (t_path**)malloc(sizeof(t_path*) * (i + 1));
	while (i >= 0)
		tmp[i--] = NULL;
	p = 0;
	while (++i < nb_valid_next(st, *room))
		if ((*room)->hall[s_i_valid(*room, i + 1, st)] && !(*room)->hall[s_i_valid(*room, i + 1, st)]->pass)
		{
			if (recur_path(st, &t, &((*room)->hall[s_i_valid(*room, i + 1, st)]), pt))
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

int		verif_fin(t_salle **room, t_stap *st, t_allp **pt)
{
	if (!ft_strcmp((*room)->flag, "end"))
		return (1);
	if (!nb_valid_next(st, *room) || !ft_strcmp((*room)->flag, "start")
		|| (*room)->pass == 1 || !verif_d(*pt, (*room)->name))
		return (0);
	return (-1);
}
