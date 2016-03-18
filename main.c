/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:23:39 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/18 08:34:06 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		salle_len(t_salle *room)
{
	int	i;

	i = 0;
	while(room)
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

void	affiche_path(t_path *p)
{
	while (p)
	{
		write(1, p->name, ft_strlen(p->name));
		write(1, "-", 1);
		p = p->next;
	}
}

void	affiche_allp(t_allp *p)
{
	while (p)
	{
		affiche_path(p->path);
		ft_putnbr(p->nb_hall);
		p = p->next;
		write(1, "\n", 1);
	}
}

int	main()
{
	t_salle	*h;
	int		nbr_f;
	char	*ptr;
	t_allp	*all_path;
	t_stap	st;

	if (get_next_line(0, &ptr) <= 0)
		return (0);
	nbr_f = ft_atoi(ptr);
	h = init_map(nbr_f);
	h = reverse_lst(h);
	st.start = find_flag(h, "start");
	st.stop = find_flag(h, "end");
	st.nb_room = salle_len(h);
	all_path = NULL;
	search_all_path(st, &all_path, &h);
	reinit_nb_hall(&all_path);
	verif_bouchon(&all_path);
	affiche_allp(all_path);
	tri_path(&all_path);
	return (0);
}
