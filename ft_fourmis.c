/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourmis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 08:43:11 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/18 14:27:23 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		add_fourmis_end(t_fourmis **prems, t_fourmis *elem)
{
	t_fourmis	*tmp;

	tmp = *prems;
	if (!tmp)
	{
		*prems = elem;
		return ;
	}
	while (prems->next)
		prems = prems->next;
	prems->next = elem;
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
	while (i <= i_fourmis && path->next)
	{
		path = path->next;
		i += path->nb_hall - 2;
	}
	return (path);
}

t_fourmis	**init_fourmis(int nb_f, t_allp *path)
{
	t_fourmis	**creat;
	t_fourmis	*tmp;
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
		if (ft_strcmp(tmp->path->next->name, creat[nb_path]->path->next->name)
			&& creat[nb_path])
			nb_path--;
		add_fourmis_end(&creat[nb_path], new_fourmis(f_rest + 1, tmp));
	}
	f_rest = 0;
	return (creat);
}
