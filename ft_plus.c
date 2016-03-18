/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:34:56 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/18 10:38:48 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		path_len(t_path *p)
{
	int	i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void	print_lst(t_file *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->str);
		lst = lst->next;
	}
}

t_salle	*new_hall(char *name, char *flag, t_salle *next, int id)
{
	t_salle	*prout;

	prout = (t_salle*)malloc(sizeof(t_salle));
	prout->hall = NULL;
	prout->next = next;
	prout->id = id;
	prout->pass = 0;
	prout->name = (char*)ft_strnew(sizeof(char) * (ft_strlen(name) + 1));
	if (flag)
	{
		prout->flag = ft_strnew(ft_strlen(flag) + 1);
		ft_strcpy(prout->flag, flag);
	}
	else
		prout->flag = NULL;
	ft_strcpy(prout->name, name);
	return (prout);
}
