/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:37:54 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/14 10:04:08 by cdrouet          ###   ########.fr       */
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

t_salle	*init_map(void)
{
	int		ret;
	char	*str;
	t_salle	*map;
	char	**line;

	while ((ret = get_next_line(0, &str)) > 0)
	{
		if (str[0] == '#' && str[1] == '#' && !ft_strcmp(&str[2], "start"))
		{
			free(str);
			if ((ret = get_next_line(0, &str)) > 0)

		}
	}
}
