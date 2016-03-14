/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:37:54 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/14 11:41:20 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_salle	*new_hall(char *name)
{
	t_salle	*prout;

	prout = (t_salle*)malloc(sizeof(t_salle));
	prout->hall = NULL;
	prout->next = NULL;
	prout->name = (char*)ft_strnew(sizeof(char) * (ft_strlen(name) + 1));
	prout->flag = NULL;
	ft_strcpy(prout->name, name);
	return (prout);
}

int		verif_hall_tun(char *str)
{
	int	i;
	int nb;

	if (!ft_strchr(str, ' '))
		return (1);
	nb = 0;
	i = 0;
	while (str[i])
		if (str[i++] == ' ')
			nb++;
	if (nb == 2)
		return (0);
	return (-1);
}

t_salle	*init_map(void)
{
	t_file	*hall;
	t_file	*tunnel;
	t_salle	*ha;
	int		ret;
	char	*str;

	hall = NULL;
	tunnel = NULL;
	ha = NULL;
	while ((ret = get_next_line(0, &str)) > 0)
	{
		if (!(str[0] == '#' && str[1] != '#'))
		{
			if (str[0] == '#' && str[1] == '#')
			{
				if ((ret = get_next_line(0, &str)) > 0)
					add_end_lst(&hall, file_new(str, &str[2]));
			}
			else if (verif_hall_tun(str) == 0)
				add_end_lst(&hall, file_new(str, NULL));
			else if (verif_hall_tun(str) == 1)
				add_end_lst(&tunnel, file_new(str, NULL));
			else if (verif_hall_tun(str) == -1)
				break ;
		}
		free(str);
	}
	if (ret == -1)
		return (NULL);
	return (ha);
}
