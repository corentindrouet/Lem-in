/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:05:21 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/16 10:57:28 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		search_index_low_path(t_path **path)
{
	int	min;
	int	i;
	int	index;

	i = -1;
	min = path_len(path[0]);
	index = 0;
	while (path[++i] != NULL)
		if (min > path_len(path[i]))
		{
			min = path_len(path[i]);
			index = i;
		}
	return (index);
}

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
