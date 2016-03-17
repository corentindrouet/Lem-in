/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:59:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/17 13:09:37 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_fourmis

void	pass_fourmis(t_salle *room, t_allp *path, int nb_f)
{
	t_salle		*fin;
	t_fourmis	*f;

	fin = find_flag(room, "end");
	room->pass = nb_f;
	while (fin->pass < nb_f)
	{
		
	}
}
