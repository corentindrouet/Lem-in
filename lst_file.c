/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 10:36:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/14 15:13:08 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_file	*file_new(char *str, char *flag)
{
	t_file	*ret;

	ret = (t_file*)malloc(sizeof(t_file));
	ret->str = ft_strnew(ft_strlen(str) + 1);
	ft_strcpy(ret->str, str);
	if (flag)
	{
		ret->flag = ft_strnew(ft_strlen(flag) + 1);
		ft_strcpy(ret->flag, flag);
	}
	else
		ret->flag = NULL;
	ret->next = NULL;
	return (ret);
}

int		lst_len(t_file *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		id_lst(t_salle *room, char *str)
{
	while (room)
	{
		if (!ft_strcmp(str, room->name))
			return (room->id);
		room = room->next;
	}
	return (-1);
}

void	add_end_lst(t_file **str, t_file *elem)
{
	t_file	*temp;

	temp = *str;
	if (!temp)
		*str = elem;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = elem;
	}
}

void	print_lst(t_file *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->str);
		lst = lst->next;
	}
}
