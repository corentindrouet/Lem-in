/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourmis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 08:43:11 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/21 08:57:31 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		add_fourmis_end(t_fourmis ***prems, t_fourmis *elem, int nb_path)
{
	t_fourmis	**tmp;

	tmp = (*prems);
	if (!tmp[nb_path])
	{
		tmp[nb_path] = elem;
		return ;
	}
	while (tmp[nb_path]->next)
		tmp[nb_path] = tmp[nb_path]->next;
	tmp[nb_path]->next = elem;
	return ;
}

t_fourmis	*new_fourmis(int id, t_path *path)
{
	t_fourmis	*f;

	f = (t_fourmis*)malloc(sizeof(t_fourmis));
	f->id = id;
	f->path = path;
	f->arrive = 0;
	f->next = NULL;
	return (f);
}

t_path		*path_index(t_allp *path, int i_fourmis)
{
	int		i;

	i = path->nb_hall - 2;
	while (i < i_fourmis && path->next)
	{
		path = path->next;
		i += (path->nb_hall - 2);
	}
	return (path->path);
}

void		aff_fourmis(t_fourmis *p)
{
	while (p)
	{
//		ft_printf("%s-", p->path->next->name);
		p = p->next;
	}
}

t_fourmis	**init_fourmis(int nb_f, t_allp *path)
{
	t_fourmis	**creat;
	t_path		*tmp;
	int			f_rest;
	int			nb_path;

	nb_path = allp_len(path);
	creat = (t_fourmis**)malloc(sizeof(t_fourmis*) * (nb_path + 1));
	f_rest = -1;
	while (++f_rest <= nb_path)
		creat[f_rest] = NULL;
	f_rest = -1;
	nb_path--;
	while (++f_rest < nb_f)
	{
		tmp = path_index(path, nb_f - f_rest);
		if (creat[nb_path] &&
			ft_strcmp(tmp->next->name, creat[nb_path]->path->next->name))
			nb_path--;
		add_fourmis_end(&creat, new_fourmis(f_rest + 1, tmp), nb_path);
	}
	f_rest = -1;
	nb_path = allp_len(path);
	while (++f_rest < nb_path)
		if (creat[f_rest])
			aff_fourmis(creat[f_rest]);
	return (creat);
}
