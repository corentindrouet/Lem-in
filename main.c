/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:23:39 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/15 09:14:15 by cdrouet          ###   ########.fr       */
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

void	affiche_salle(t_salle *room)
{
	int	i;
	int	len;

	len = salle_len(room);
	while (room)
	{
		i = -1;
		ft_printf("salle : %s | flag : %s\n", room->name, room->flag);
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

	if (get_next_line(0, &ptr) <= 0)
		return (0);
	nbr_f = ft_atoi(ptr);
	h = init_map();
	h = reverse_lst(h);
	affiche_salle(h);
	return (0);
}
