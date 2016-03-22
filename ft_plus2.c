/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:04:47 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/22 13:17:35 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	assign_room(t_salle *room, char ***tun, int halllen)
{
	t_salle	*start;
	int		i;

	start = room;
	while (room)
	{
		i = 0;
		room->hall = (t_salle**)malloc(sizeof(t_salle*) * (halllen + 1));
		while (i <= halllen)
			room->hall[i++] = NULL;
		i = 0;
		while (tun[i])
		{
			if (!ft_strcmp(tun[i][0], room->name))
				room->hall[id_lst(start, tun[i][1])] = p_lst(start, tun[i][1]);
			else if (!ft_strcmp(tun[i][1], room->name))
				room->hall[id_lst(start, tun[i][0])] = p_lst(start, tun[i][0]);
			i++;
		}
		room = room->next;
	}
}

int		no_comment_line(char *str, t_init *ini, int *ret, int *i)
{
	if (str[0] == '#' && str[1] == '#')
		commande(str, ini, i, ret);
	else if (verif_hall(str) == 1)
		add_end_lst(&((*ini).hall), file_new(str, NULL));
	else if (verif_tun(str) == 1)
		add_end_lst(&((*ini).tunnel), file_new(str, NULL));
	else
		return (0);
	return (1);
}

void	commande(char *str, t_init *ini, int *i, int *ret)
{
	char	*tmpflag;

	tmpflag = &str[2];
	if (!ft_strcmp(&str[2], "start"))
	{
		(*i)++;
		if (((*ret) = get_next_line(0, &str)) > 0)
			add_start_lst(&(ini->hall), file_new(str, tmpflag));
	}
	else if (!ft_strcmp(&str[2], "end"))
		if (((*ret) = get_next_line(0, &str)) > 0)
			ini->stop = file_new(str, tmpflag);
}
