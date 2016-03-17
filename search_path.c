/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 09:16:52 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/17 08:14:59 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

t_path	*new_path(char *name)
{
	t_path	*ne;

	ne = (t_path*)malloc(sizeof(t_path));
	ne->name = (char*)ft_strnew(sizeof(char) * (ft_strlen(name) + 1));
	ft_strcpy(ne->name, name);
	ne->next = NULL;
	return (ne);
}

void	add_path_end(t_path **lst, t_path *new)
{
	if (!(*lst))
		(*lst) = new;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
	}
}

int		nb_next(t_stap *st, t_salle *room)
{
	int	i;
	int	len;
	int	compt;

	len = st->nb_room;
	i = -1;
	compt = 0;
	while (++i < len)
	{
		if (room->hall[i])
			compt++;
	}
	return (compt);
}

int		recur_path(t_stap *st, t_path **pat, t_salle *room)
{
	int		i;
	int		p;
	t_path	**tmp;
	t_path	*t;

	i = nb_next(st, room);
	add_path_end(pat, new_path(room->name));
	//*pat = (*pat)->next;
	t = (*pat)->next;
	tmp = (t_path**)malloc(sizeof(t_path*) * (i + 1));
	while (i >= 0)
		tmp[i--] = NULL;
	if (!ft_strcmp(room->flag, "end"))
		return (1);
	if (!nb_next(st, room) || !ft_strcmp(room->flag, "start") || room->pass == 1)
		return (0);
	while (!room->hall[i])
		i++;
	if (nb_next(st, room) == 1)
		return (recur_path(st, &t, room->hall[i]));
	room->pass = 1;
	p = 0;
	i = -1;
	while (++i < st->nb_room)
	{
		if (room->hall[i])
		{
			if (recur_path(st, &t, room->hall[i]))
			{
				tmp[p++] = t->next;
			}
			else
				free_path(&t);
			t->next = NULL;
		}
	}
	room->pass = 0;
	if (tmp[0] == NULL)
		return (0);
	t->next = tmp[search_index_low_path(tmp)];
	return (1);
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
		p = p->next;
		write(1, "\n", 1);
	}
}

int		search_all_path(t_stap st, t_allp *pat, t_salle *room)
{
	int		i;
	int		lenroom;
	int		nb_path;
	t_allp	*tmp;

	(void)st;
	i = -1;
	lenroom = salle_len(room);
	nb_path = 0;
	while (++i < lenroom)
	{
		if (room->hall[i])
		{
			if (!strcmp(room->flag, "start"))
				add_allp_end(&pat, new_allp(new_path(room->name)));
			nb_path++;
		}
	}
	i = -1;
	tmp = pat;
	room->pass = 1;
	while (++i < lenroom)
	{
		if (room->hall[i])
		{
			if (!recur_path(&st, &(tmp->path), room->hall[i]))
				tmp = free_allp(&tmp, &pat);
			else
				tmp = tmp->next;
		}
	}
	affiche_allp(pat);
	return (0);
}
