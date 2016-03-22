/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:34:56 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/22 12:56:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			path_len(t_path *p)
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

t_fourmis	*new_fourmis(int id, t_path *path)
{
	t_fourmis	*f;

	f = (t_fourmis*)malloc(sizeof(t_fourmis));
	f->id = id;
	f->path = path;
	f->arrive = 0;
	f->next = NULL;
	return (f);
}

void		print_lst(t_file *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->str);
		lst = lst->next;
	}
}

int			verif_tun(char *str)
{
	int		i;
	int		nb;
	int		j;
	char	**split;

	if (!ft_strchr(str, '-'))
		return (-1);
	split = ft_strsplit(str, '-');
	nb = 0;
	i = 0;
	while (str[i])
		if (str[i++] == '-')
			nb++;
	i = 0;
	while (split[i])
		i++;
	j = 0;
	while (split[++j])
		free(split[j]);
	free(split);
	if (nb == 1 && i == 2)
		return (1);
	return (-1);
}

t_salle		*new_hall(char *name, char *flag, t_salle *next, int id)
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
