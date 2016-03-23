/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:19:29 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/23 09:26:37 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path	*new_path(char *name)
{
	t_path	*ne;

	if ((ne = (t_path*)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	if ((ne->name = ft_strnew(sizeof(char) * (ft_strlen(name) + 1))) == NULL)
		return (NULL);
	ft_strcpy(ne->name, name);
	ne->next = NULL;
	return (ne);
}

void	add_path_end(t_path **lst, t_path *new)
{
	t_path	*tmp;

	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		tmp = *lst;
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
	last = pt;
	if (!tmp || !(tmp->next))
		return (1);
	while (last->next)
		last = last->next;
	while (tmp->next)
	{
		if (!verif_p(tmp->path, name, path_len(last->path)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
