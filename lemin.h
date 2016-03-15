/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:25:19 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/15 08:49:01 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct		s_salle
{
	char			*name;
	char			*flag;
	int				id;
	struct s_salle	**hall;
	struct s_salle	*next;
}					t_salle;

typedef struct		s_file
{
	char			*str;
	char			*flag;
	struct s_file	*next;
}					t_file;

void				print_lst(t_file *lst);
void				add_end_lst(t_file **str, t_file *elem);
t_file				*file_new(char *str, char *flag);
t_salle				*new_hall(char *name, char *flag, t_salle *next, int id);
int					verif_hall_tun(char *str);
void				assign_tun(t_salle *room, t_file *tunnel, int halllen);
t_salle				*config(t_file *hall, t_file *tunnel);
t_salle				*init_map(void);
int					lst_len(t_file *lst);
t_salle				*p_lst(t_salle *room, char *str);
int					id_lst(t_salle *room, char *str);

#endif
