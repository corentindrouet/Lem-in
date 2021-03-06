/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:59:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/30 09:23:41 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*end_room(t_fourmis **f, t_salle **fin, t_salle **room, int color)
{
	t_fourmis	*tmp;
	t_salle		*tempo;
	char		*prout;

	tmp = *f;
	prout = (color) ? "{rouge}L%d-%s{eoc} " : "L%d-%s ";
	tempo = *room;
	tmp->arrive++;
	(*fin)->pass++;
	while (ft_strcmp(tempo->name, tmp->path->name))
		tempo = tempo->next;
	tempo->pass = 0;
	return (prout);
}

void	deplace_fourmis(t_fourmis **f, t_salle **fin, t_salle **room, int color)
{
	t_fourmis	*tmp;
	t_salle		*tempo;
	char		*prout;

	tmp = *f;
	tempo = *room;
	prout = NULL;
	if (!ft_strcmp(tmp->path->next->name, (*fin)->name))
		prout = end_room(f, fin, room, color);
	else
	{
		prout = (color && !ft_strcmp(tmp->path->name, (*room)->name))
			? "{vert}L%d-%s{eoc} " : "L%d-%s ";
		while (ft_strcmp(tempo->name, tmp->path->next->name))
			tempo = tempo->next;
		if (tempo->pass)
			return ;
		tempo->pass = 1;
		tempo = *room;
		while (ft_strcmp(tempo->name, tmp->path->name))
			tempo = tempo->next;
		tempo->pass = 0;
	}
	tmp->path = tmp->path->next;
	ft_printf(prout, tmp->id, tmp->path->name);
}

void	aff_fourmis(t_fourmis **f, int nb_f)
{
	int			i;
	t_fourmis	*tmp;

	i = -1;
	while (++i <= nb_f)
	{
		tmp = f[i];
		while (tmp)
		{
			ft_printf("%d-%s\n", tmp->id, tmp->path->next->name);
			tmp = tmp->next;
		}
	}
}

void	pass_fourmis(t_salle *room, t_allp *path, int nb_f, int color)
{
	t_salle		*fin;
	t_fourmis	**f;
	t_fourmis	*tmp;
	int			i;

	fin = find_flag(room, "end");
	fin->pass = 0;
	room->pass = nb_f;
	f = init_fourmis(nb_f, path);
	ft_putchar('\n');
	while (fin->pass < nb_f)
	{
		i = -1;
		while (f[++i])
		{
			tmp = f[i];
			while (tmp)
			{
				if (!tmp->arrive)
					deplace_fourmis(&tmp, &fin, &room, color);
				tmp = tmp->next;
			}
		}
		ft_putchar('\n');
	}
}
