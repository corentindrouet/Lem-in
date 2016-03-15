/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:23:39 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/15 14:14:48 by cdrouet          ###   ########.fr       */
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

void	affiche_salle(t_salle *room, int nbr_f)
{
	int	i;
	int	len;

	len = salle_len(room);
	ft_printf("%d\n", nbr_f);
	while (room)
	{
		i = -1;
		if (room->flag)
			ft_printf("##%s\n", room->flag);
		ft_printf("%s\n", room->name);
		while (++i <= len)
			if (room->hall[i])
				ft_printf("%s-%s\n", room->name, room->hall[i]->name);
		write(1, "\n", 1);
		room = room->next;
	}
}

int	main()
{
	t_salle	*h;
	int		nbr_f;
	char	*ptr;
	//t_path	*all_path;
	t_stap	st;

	if (get_next_line(0, &ptr) <= 0)
		return (0);
	nbr_f = ft_atoi(ptr);
	h = init_map();
	h = reverse_lst(h);
	affiche_salle(h, nbr_f);
	st.start = find_flag(h, "start");
	st.stop = find_flag(h, "stop");
	return (0);
}
