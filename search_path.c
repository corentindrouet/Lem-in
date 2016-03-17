/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 09:16:52 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/17 16:15:54 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

t_path	*new_path(char *name)
{
	t_path	*ne;

	if ((ne = (t_path*)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	if ((ne->name = (char*)ft_strnew(sizeof(char) * (ft_strlen(name) + 1))) == NULL)
		return (NULL);
	ft_strcpy(ne->name, name);
	ne->next = NULL;
	return (ne);
}

void	add_path_end(t_path **lst, t_path *new)
{
	t_path	*tmp;

	tmp = *lst;
	if (!tmp)
		tmp = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
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

void	pat_aff(t_path *tmp)
{
	while (tmp)
	{
		ft_printf("%s-", tmp->name);
		tmp = tmp->next;
	}
}

void	aff(t_path **tmp)
{
	int	i;

	i = -1;
		write(1, "\n", 1);
	while (tmp[++i])
	{
		pat_aff(tmp[i]);
		write(1, "\n", 1);
	}
}

int		verif_p(t_path *p, char *name, int len)
{
	t_path	*tmp;
	int		i;

	tmp = p;
	i = 0;
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->name, name) && i < len)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int		verif_d(t_allp *pt, char *name)
{
	t_allp	*tmp;
	t_allp	*last;

	tmp = pt;
	if (!tmp || !(tmp->next))
		return (1);
	while (tmp->next)
		tmp = tmp->next;
	last = tmp;
	tmp = pt;
	while (tmp->next)
	{
		if (!verif_p(tmp->path, name, path_len(last->path)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		recur_path(t_stap *st, t_path **pat, t_salle **room, t_allp *pt)
{
	int		i;
	int		p;
	t_path	**tmp;
	t_path	*t;

	i = nb_next(st, *room);
	add_path_end(pat, new_path((*room)->name));
	t = (*pat)->next;
	tmp = (t_path**)malloc(sizeof(t_path*) * (i + 1));
	while (i >= 0)
		tmp[i--] = NULL;
	if (!ft_strcmp((*room)->flag, "end"))
		return (1);
	if (!nb_next(st, *room) || !ft_strcmp((*room)->flag, "start") || (*room)->pass == 1
		|| !verif_d(pt, (*room)->name))
		return (0);
	while (!(*room)->hall[i])
		i++;
	if (nb_next(st, *room) == 1)
		return (recur_path(st, &t, &((*room)->hall[i]), pt));
	(*room)->pass = 1;
	p = 0;
	i = -1;
	while (++i < st->nb_room)
	{
		if ((*room)->hall[i])
		{
			if (recur_path(st, &t, &((*room)->hall[i]), pt))
			{
				tmp[p++] = t->next;
			}
			else
				free_path(&t);
			t->next = NULL;
		}
	}
	(*room)->pass = 0;
	if (tmp[0] == NULL)
		return (0);
	t->next = tmp[search_index_low_path(tmp)];
	return (1);
}

int		search_all_path(t_stap st, t_allp **pat, t_salle **room)
{
	int		i;
	int		lenroom;
	int		nb_path;
	t_allp	*tmp;

	(void)st;
	i = -1;
	lenroom = salle_len(*room);
	nb_path = 0;
	while (++i < lenroom)
	{
		if ((*room)->hall[i])
		{
			if (!strcmp((*room)->flag, "start"))
				add_allp_end(pat, new_allp(new_path((*room)->name)));
			nb_path++;
		}
	}
	i = -1;
	tmp = *pat;
	(*room)->pass = 1;
	while (++i < lenroom)
	{
		if ((*room)->hall[i])
		{
			if (!recur_path(&st, &(tmp->path), &((*room)->hall[i]), *pat))
				tmp = free_allp(&tmp, pat);
			else
				tmp = tmp->next;
		}
	}
	return (0);
}
