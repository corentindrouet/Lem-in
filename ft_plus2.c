/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:04:47 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/24 08:24:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	assign_room(t_salle **room, char ***tun, int halllen)
{
	t_salle	*start;
	t_salle	*tmp;
	int		i;

	(void)halllen;
	start = *room;
	tmp = *room;
	while (tmp)
	{
		i = 0;
		while (tun[i])
		{
			if (!ft_strcmp(tun[i][0], tmp->name))
				tmp->hall[id_lst(start, tun[i][1])] = p_lst(start, tun[i][1]);
			else if (!ft_strcmp(tun[i][1], tmp->name))
				tmp->hall[id_lst(start, tun[i][0])] = p_lst(start, tun[i][0]);
			i++;
		}
		tmp = tmp->next;
	}
}

int		no_comment_line(char *str, t_init *ini, int *ret, int *i)
{
	if (str[0] == '#' && str[1] == '#')
		commande(str, ini, i, ret);
	else if (verif_hall(str) == 1)
		add_end_lst(&(ini->hall), file_new(str, NULL));
	else if (verif_tun(str) == 1)
		add_end_lst(&(ini->tunnel), file_new(str, NULL));
	else
		return (0);
	return (1);
}

void	commande(char *str, t_init *ini, int *i, int *ret)
{
	char	*tmpflag;
	char	*tmp;

	tmpflag = &str[2];
	if (!ft_strcmp(&str[2], "start"))
	{
		(*i)++;
		if (((*ret) = get_next_line(0, &tmp)) > 0)
			add_start_lst(&(ini->hall), file_new(tmp, tmpflag));
		free(tmp);
	}
	else if (!ft_strcmp(&str[2], "end"))
		if (((*ret) = get_next_line(0, &tmp)) > 0)
			ini->stop = file_new(tmp, tmpflag);
}
