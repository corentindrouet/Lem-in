/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourmis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 08:43:11 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/18 11:59:32 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_fourmis	*new_fourmis(int id, t_salle *name, t_path *path)
{
	t_fourmis	*f;

	f = (t_fourmis*)malloc(sizeof(t_fourmis));
	f->id = id;
	f->name = name;
	f->path = path;
	return (f);
}

t_fourmis	*init_fourmis(int nb_f, t_salle *room, t_path *path)
{
	t_fourmis	*creat;

	
}
