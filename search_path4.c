/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:42:17 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/23 15:08:51 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_all_path(t_stap st, t_salle *room, t_allp ***opti)
{
	int	i;
	int	j;
	int lenroom;

	(*opti) = (t_allp**)malloc(sizeof(t_allp*) * (nb_next(&st, room) + 1));
	i = -1;
	lenroom = salle_len(room);
	while (++i < nb_next(&st, room))
	{
		j = -1;
		while (++j < lenroom)
			if (room->hall[j])
				if (!ft_strcmp(room->flag, "start"))
				add_allp_end(&((*opti)[i]), new_allp(new_path(room->name)));
	}
	opti[i] = NULL;
}
