/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:37:54 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/18 10:39:46 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		verif_hall_tun(char *str)
{
	int	i;
	int nb;

	if (!ft_strchr(str, ' '))
		return (1);
	nb = 0;
	i = 0;
	while (str[i])
		if (str[i++] == ' ')
			nb++;
	if (nb == 2)
		return (0);
	return (-1);
}

void	assign_tun(t_salle *room, t_file *tunnel, int halllen)
{
	char	***tun;
	int		i;
	int		len_tunnel;
	t_salle	*start;

	len_tunnel = lst_len(tunnel);
	tun = (char***)malloc(sizeof(char**) * (len_tunnel + 1));
	tun[len_tunnel] = NULL;
	i = 0;
	while (tunnel)
	{
		tun[i++] = ft_strsplit(tunnel->str, '-');
		tunnel = tunnel->next;
	}
	start = room;
	while (room)
	{
		i = 0;
		room->hall = (t_salle**)malloc(sizeof(t_salle*) * (halllen + 1));
		while (i <= halllen)
			room->hall[i++] = NULL;
		i = 0;
		while (i < len_tunnel)
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
	assign_tun(room, tunnel, halllen);
	return (room);
}

void	affiche_all(t_file *hall, t_file *tun, int nb_f)
{
	ft_putnbr(nb_f);
	write(1, "\n", 1);
	while (hall)
	{
		if (hall->flag)
			ft_printf("##%s\n", hall->flag);
		ft_printf("%s\n", hall->str);
		hall = hall->next;
	}
	while (tun)
	{
		ft_printf("%s\n", tun->str);
		tun = tun->next;
	}
}

t_salle	*init_map(int nb_f)
{
	t_file	*hall;
	t_file	*tunnel;
	int		ret;
	char	*str;
	char	*tmpflag;
	t_file	*stop;

	hall = NULL;
	tunnel = NULL;
	while ((ret = get_next_line(0, &str)) > 0)
	{
		if (!(str[0] == '#' && str[1] != '#'))
		{
			if (str[0] == '#' && str[1] == '#')
			{
				tmpflag = &str[2];
				if (!ft_strcmp(&str[2], "start"))
				{
					if ((ret = get_next_line(0, &str)) > 0)
						add_start_lst(&hall, file_new(str, tmpflag));
				}
				else if (!ft_strcmp(&str[2], "end"))
					if ((ret = get_next_line(0, &str)) > 0)
						stop = file_new(str, tmpflag);
			}
			else if (verif_hall_tun(str) == 0)
				add_end_lst(&hall, file_new(str, NULL));
			else if (verif_hall_tun(str) == 1)
				add_end_lst(&tunnel, file_new(str, NULL));
			else if (verif_hall_tun(str) == -1)
				break ;
		}
		free(str);
	}
	add_end_lst(&hall, stop);
	affiche_all(hall, tunnel, nb_f);
	if (ret == -1)
		return (NULL);
	return (config(hall, tunnel));
}
