/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:23:39 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/30 09:19:27 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int		salle_len(t_salle *room)
{
	int	i;

	i = 0;
	while (room)
	{
		i++;
		room = room->next;
	}
	return (i);
}

t_salle	*reverse_lst(t_salle *room)
{
	t_salle	*tmp;
	t_salle	*nex;

	tmp = NULL;
	nex = NULL;
	while (room)
	{
		nex = room->next;
		room->next = tmp;
		tmp = room;
		if (nex == NULL)
			break ;
		room = nex;
	}
	return (room);
}

void	exit_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}

int		main(void)
{
	t_salle	*h;
	t_init	all;
	char	*ptr;
	t_allp	*all_path;
	t_stap	st;

	if (get_next_line(0, &ptr) <= 0)
		return (0);
	all.nb_f = ((int)ft_strlen(ptr) <= 13) ? ft_atol(ptr) : -1;
	free(ptr);
	if (!(h = init_map(&all)) || all.nb_f <= 0 || all.nb_f >= 2147483648)
		exit_error("Error\n");
	h = reverse_lst(h);
	st.start = find_flag(h, "start");
	st.stop = find_flag(h, "end");
	st.nb_room = salle_len(h);
	all_path = NULL;
	if (!search_all_path(st, &all_path, &h))
		exit_error("Error\n");
	reinit_nb_hall(&all_path);
	verif_bouchon(&all_path);
	tri_path(&all_path);
	affiche(all);
	pass_fourmis(h, all_path, all.nb_f, all.color);
	return (0);
}
