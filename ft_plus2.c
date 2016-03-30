/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:04:47 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/30 11:13:26 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		verif_dooble_hall(char *str, t_init *ini)
{
	char	*tmp;
	char	*tmp2;
	t_file	*tem;

	tem = ini->hall;
	tmp2 = ft_strsub(str, 0, ft_strchr(str, ' ') - str);
	tmp = NULL;
	if (ini->stop)
	{
		tmp = ft_strsub(ini->stop->str,
			0, ft_strchr(ini->stop->str, ' ') - ini->stop->str);
		if (!ft_strcmp(tmp, tmp2))
			return (0);
		free(tmp);
	}
	while (tem)
	{
		tmp = ft_strsub(tem->str, 0, ft_strchr(tem->str, ' ') - tem->str);
		if (!ft_strcmp(tmp, tmp2))
			return (0);
		free(tmp);
		tem = tem->next;
	}
	free(tmp2);
	return (1);
}

void	affiche(t_init prout)
{
	t_file	*tmp;

	ft_putnbr(prout.nb_f);
	write(1, "\n", 1);
	tmp = prout.hall;
	while (tmp)
	{
		if (tmp->flag)
			ft_printf("##%s\n", tmp->flag);
		ft_putendl(tmp->str);
		tmp = tmp->next;
	}
	tmp = prout.tunnel;
	while (tmp)
	{
		ft_putendl(tmp->str);
		tmp = tmp->next;
	}
}

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
			if (!ft_strcmp(tun[i][0], tmp->name)
				&& id_lst(start, tun[i][1]) != -1)
				tmp->hall[id_lst(start, tun[i][1])] = p_lst(start, tun[i][1]);
			else if (!ft_strcmp(tun[i][1], tmp->name)
				&& id_lst(start, tun[i][0]) != -1)
				tmp->hall[id_lst(start, tun[i][0])] = p_lst(start, tun[i][0]);
			i++;
		}
		tmp = tmp->next;
	}
}

int		no_comment_line(char *str, t_init *ini, int *ret, int *i)
{
	if (str[0] == '#' && str[1] == '#')
		return (commande(str, ini, i, ret));
	else if (verif_hall(str) == 1 && verif_dooble_hall(str, ini))
		add_end_lst(&(ini->hall), file_new(str, NULL));
	else if (verif_tun(str) == 1)
		add_end_lst(&(ini->tunnel), file_new(str, NULL));
	else
		return (0);
	return (1);
}

int		commande(char *str, t_init *ini, int *i, int *ret)
{
	char	*tmpflag;
	char	*tmp;

	tmpflag = &str[2];
	if (!ft_strcmp(&str[2], "start"))
	{
		(*i)++;
		if (((*ret) = get_next_line(0, &tmp)) <= 0
			|| !verif_dooble_hall(tmp, ini))
			return (0);
		add_start_lst(&(ini->hall), file_new(tmp, tmpflag));
		free(tmp);
	}
	else if (!ft_strcmp(&str[2], "end"))
	{
		if (ini->stop || ((*ret) = get_next_line(0, &tmp)) <= 0
			|| !verif_dooble_hall(tmp, ini))
			return (0);
		ini->stop = file_new(tmp, tmpflag);
		free(tmp);
	}
	else if (!ft_strcmp(&str[2], "color"))
		ini->color = 1;
	return (1);
}
