/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 08:24:58 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/17 08:52:58 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reinit_nb_hall(t_allp **all_path)
{
	t_allp	*tmp;

	tmp = *all_path;
	while (tmp)
	{
		tmp->nb_hall = path_len(tmp->path);
		tmp = tmp->next;
	}
}
/*
void	verif_bouchon(t_allp *all_path)
{
	t_allp	*tmp_i;
	t_allp	*tmp_j;


}*/
