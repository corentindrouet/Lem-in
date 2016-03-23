/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:23:39 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/23 10:57:28 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	aff(t_allp *path)
{
	t_path	*p;

	while (path)
	{
		p = path->path;
		while (p)
		{
			ft_printf("%s-", p->name);
			p = p->next;
		}
		write(1, "\n", 1);
		path = path->next;
	}
}

int		main(void)
{
	t_salle	*h;
	long	nbr_f;
	char	*ptr;
	t_allp	*all_path;
	t_stap	st;

	if (get_next_line(0, &ptr) <= 0)
		return (0);
	nbr_f = ((int)ft_strlen(ptr) <= 13) ? ft_atol(ptr) : -1;
	if (!(h = init_map()) || nbr_f <= 0 || nbr_f >= 2147483648)
		exit_error("Error\n");
	h = reverse_lst(h);
	st.start = find_flag(h, "start");
	st.stop = find_flag(h, "end");
	st.nb_room = salle_len(h);
	all_path = NULL;
	if (!search_all_path(st, &all_path, &h))
		exit_error("Error\n");
	aff(all_path);
	reinit_nb_hall(&all_path);
	verif_bouchon(&all_path);
	tri_path(&all_path);
	pass_fourmis(h, all_path, nbr_f);
	return (0);
}
