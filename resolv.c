/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:59:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/18 15:54:16 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	deplace_fourmis(t_fourmis **f, t_salle *fin, t_salle **room)
{
	t_fourmis	*tmp;
	t_salle		*tempo;

	tmp = *f;
	tmp->path = tmp->path->next;
	tempo = *room;
	while (tempo && ft_strcmp(tempo->name, tmp->path->name))
		tempo = tempo->next;
	if (tempo->pass)
		return ;
	if (!tempo->flag)
		tempo->pass = 1;
	if (!ft_strcmp(tmp->path->name, fin->name))
		tmp->arrive++;
	ft_printf("L%d-%s ", tmp->id, tmp->path->name);
}

void	pass_fourmis(t_salle *room, t_allp *path, int nb_f)
{
	t_salle		*fin;
	t_fourmis	**f;
	t_fourmis	*tmp;
	int			i;

	fin = find_flag(room, "end");
	room->pass = nb_f;
	f = NULL;
	f = init_fourmis(nb_f, path);
	while (fin->pass < nb_f)
	{
		i = -1;
		while (f[++i])
		{
	//	write(1, "o", 1);
			tmp = f[i];
			while (tmp)
			{
				if (!tmp->arrive)
					deplace_fourmis(&tmp, fin, &room);
				tmp = tmp->next;
			}
		}
	}
}
