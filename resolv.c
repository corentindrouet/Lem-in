/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:59:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/21 13:55:24 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	deplace_fourmis(t_fourmis **f, t_salle **fin, t_salle **room)
{
	t_fourmis	*tmp;
	t_salle		*tempo;

	tmp = (*f);
	tempo = *room;
	while (tempo && ft_strcmp(tempo->name, tmp->path->name))
		tempo = tempo->next;
	tempo->pass = 0;
	tempo = *room;
	tmp->path = tmp->path->next;
	while (tempo && ft_strcmp(tempo->name, tmp->path->name))
		tempo = tempo->next;
	if (tempo->pass)
		return ;
	if (!tempo->flag)
		tempo->pass = 1;
	if (!ft_strcmp(tmp->path->name, (*fin)->name))
	{
		tmp->arrive++;
		(*fin)->pass++;
	}
	ft_printf("L%d-%s ", tmp->id, tmp->path->name);
}

void	aff_fourmis(t_fourmis **f, int nb_f)
{
	int	i;
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

void	pass_fourmis(t_salle *room, t_allp *path, int nb_f)
{
	t_salle		*fin;
	t_fourmis	**f;
	t_fourmis	*tmp;
//	t_fourmis	*l;
	int			i;

	fin = find_flag(room, "end");
	fin->pass = 0;
	room->pass = nb_f;
	f = NULL;
	f = init_fourmis(nb_f, path);
	ft_putchar('\n');
	aff_fourmis(f, allp_len(path));
	while (fin->pass < nb_f)
	{
		i = -1;
		while (f[++i])
		{
			tmp = f[i];
			while (tmp)
			{
				if (!tmp->arrive)
					deplace_fourmis(&tmp, &fin, &room);
				tmp = tmp->next;
			}
		}
		ft_putchar('\n');
	}
}
