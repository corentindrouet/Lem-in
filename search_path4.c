/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:42:17 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/24 09:29:42 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_allp	**init_all_path(t_stap st, t_salle **room, int *t)
{
	int		i;
	int		j;
	t_allp	**opti;

	opti = (t_allp**)malloc(sizeof(t_allp*) * (nb_next(&st, *room) + 1));
	i = -1;
	while (++i < nb_next(&st, *room))
	{
		j = -1;
		while (++j < st.nb_room)
		{
			if ((*room)->hall[j])
				if (!ft_strcmp((*room)->flag, "start"))
					add_allp_end(&(opti[i]), new_allp(new_path((*room)->name)));
		}
	}
	opti[i] = NULL;
	(*room)->pass = 1;
	t[1] = -1;
	t[3] = 0;
	return (opti);
}

void	recur_ok(t_allp **o, t_allp **tmp, int *t)
{
	verif_bouchon(o);
	(*tmp) = (*tmp)->next;
	(*t)++;
}

void	end_room_hall(int *t)
{
	t[2] = -1;
	t[0]++;
}
