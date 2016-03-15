/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 09:16:52 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/15 15:07:05 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	search_all_path(t_stap st, t_path *pat, t_salle *room, int rec)
{
	int	i;
	int	lenroom;

	if (!ft_strcmp(room->flag, "stop"))
		return (1);
	i = 0;
	lenroom = salle_len(room);
	while (i < lenroom)
	{
		if (room->hall[i])
		{

		}
	}
}
