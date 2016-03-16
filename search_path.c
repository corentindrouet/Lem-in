/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 09:16:52 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/16 09:02:33 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path	*new_path(char *name)
{
	t_path	*ne;

	ne = (t_path*)malloc(sizeof(t_path));
	ne->name = (char*)ft_strnew(sizeof(char) * (ft_strlen(name) + 1));
	ft_strcpy(ne->name, name);
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

void	affiche_tallp(t_allp *p)
{
	while (p)
	{
		ft_printf("%s\n", p->path->name);
		p = p->next;
	}
}

int		recur_path(t_stap st, t_allp *pat, t_salle *room)
{

}

int		search_all_path(t_stap st, t_allp *pat, t_salle *room)
{
	int	i;
	int	lenroom;

	(void)st;
	i = -1;
	lenroom = salle_len(room);
	while (++i < lenroom)
	{
		if (room->hall[i])
		{
			if (!strcmp(room->flag, "start"))
				add_allp_end(&pat, new_allp(new_path(room->name)));
		}
	}
	affiche_tallp(pat);
	return (0);
}
