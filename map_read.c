/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:37:54 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/30 09:22:08 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		verif_hall(char *str)
{
	int		i;
	int		nb;
	int		j;
	char	**split;

	if (!ft_strchr(str, ' '))
		return (-1);
	split = ft_strsplit(str, ' ');
	nb = 0;
	i = 0;
	while (str[i])
		if (str[i++] == ' ')
			nb++;
	i = 0;
	while (split[i])
		i++;
	j = -1;
	while (split[++j])
		free(split[j]);
	free(split);
	if (nb == 2 && i == 3)
		return (1);
	return (-1);
}

void	assign_tun(t_salle **room, t_file *tunnel, int halllen)
{
	char	***tun;
	int		i;
	int		len_tunnel;

	len_tunnel = lst_len(tunnel);
	tun = (char***)malloc(sizeof(char**) * (len_tunnel + 1));
	tun[len_tunnel] = NULL;
	i = 0;
	while (tunnel)
	{
		tun[i++] = ft_strsplit(tunnel->str, '-');
		if (!ft_strcmp(tun[i - 1][0], tun[i - 1][1]))
		{
			free(tun[--i][1]);
			free(tun[i][0]);
			free(tun[i]);
			tun[i] = NULL;
		}
		tunnel = tunnel->next;
	}
	assign_room(room, tun, halllen);
}

t_salle	*config(t_file *hall, t_file *tunnel)
{
	t_salle	*room;
	int		halllen;
	int		id;
	int		p;

	room = NULL;
	halllen = lst_len(hall);
	id = 0;
	while (hall)
	{
		room = new_hall(ft_strsub(hall->str, 0,
			ft_strchr(hall->str, ' ') - hall->str), hall->flag, room, id);
		room->hall = (t_salle**)malloc(sizeof(t_salle*) * (halllen + 1));
		p = -1;
		while (++p <= halllen)
			room->hall[p] = NULL;
		hall = hall->next;
		id++;
	}
	assign_tun(&room, tunnel, halllen);
	return (room);
}

t_salle	*init_map(t_init *ini)
{
	int		ret;
	int		i;
	char	*str;

	ini->hall = NULL;
	ini->tunnel = NULL;
	ini->color = 0;
	i = 0;
	ini->stop = NULL;
	while ((ret = get_next_line(0, &str)) > 0)
	{
		if (!(str[0] == '#' && str[1] != '#'))
			if (!no_comment_line(str, ini, &ret, &i))
				break ;
		free(str);
	}
	add_end_lst(&(ini->hall), ini->stop);
	if (ret == -1 || i != 1 || !ini->stop)
		return (NULL);
	return (config(ini->hall, ini->tunnel));
}
