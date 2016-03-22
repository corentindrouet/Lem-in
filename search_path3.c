/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:24:49 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/22 13:35:22 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		verif_fin(t_salle **room, t_stap *st, t_allp **pt)
{
	if (!ft_strcmp((*room)->flag, "end"))
		return (1);
	if (!nb_next(st, *room) || !ft_strcmp((*room)->flag, "start")
		|| (*room)->pass == 1 || !verif_d(*pt, (*room)->name))
		return (0);
	return (-1);
}
