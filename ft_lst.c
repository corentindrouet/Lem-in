/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:05:21 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/15 13:21:30 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_start_lst(t_file **hall, t_file *elem)
{
	elem->next = *hall;
	*hall = elem;
}

t_salle	*find_flag(t_salle *room, char *str)
{
	while (room)
	{
		if (room->flag)
			if (!ft_strcmp(room->flag, str))
				return (room);
		room = room->next;
	}
	return (NULL);
}
