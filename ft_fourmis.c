/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourmis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 08:43:11 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/29 15:54:28 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		add_fourmis_end(t_fourmis ***prems, t_fourmis *elem, int nb_path)
{
	t_fourmis	**tmp;
	t_fourmis	*p;

	tmp = (*prems);
	if (!tmp[nb_path])
	{
		(*prems)[nb_path] = elem;
		return ;
	}
	p = tmp[nb_path];
	while (p->next)
		p = p->next;
	p->next = elem;
	return ;
}

t_path		*copy_path(t_path *p)
{
	t_path	*ret;

	ret = NULL;
	while (p)
	{
		add_path_end(&ret, new_path(p->name));
		p = p->next;
	}
	return (ret);
}

t_path		*path_index(t_allp *path, int i)
{
	t_allp	*tmp;

	tmp = path;
	while (i--)
		path = path->next;
	return (copy_path(path->path));
}

int			total_len(t_allp *path, int nb)
{
	int	res;

	res = 0;
	while (nb--)
	{
		res += (path->nb_hall - 2);
		path = path->next;
	}
	return (res);
}

t_fourmis	**init_fourmis(int nb_f, t_allp *path)
{
	t_fourmis	**creat;
	int			f_rest;
	int			nb_path;
	int			i;

	nb_path = allp_len(path);
	creat = (t_fourmis**)malloc(sizeof(t_fourmis*) * (nb_path + 1));
	f_rest = -1;
	while (++f_rest <= nb_path)
		creat[f_rest] = NULL;
	f_rest = 0;
	while (f_rest < nb_f)
	{
		while ((nb_f - f_rest) <= total_len(path, nb_path) &&
			(nb_f - f_rest) <= total_len(path, nb_path - 1) && nb_path > 1)
			nb_path--;
		i = -1;
		while (++i < nb_path && f_rest < nb_f)
			add_fourmis_end(&creat,
				new_fourmis(++f_rest, path_index(path, i)), i);
	}
	nb_path = allp_len(path);
	return (creat);
}
