/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:25:19 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/15 15:07:13 by cdrouet          ###   ########.fr       */
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

typedef struct		s_path
{
	char			**path;
	int				nb_hall;
	struct s_path	*next;
}					t_path;

typedef struct		s_stap
{
	t_salle			*start;
	t_salle			*stop;
}					t_stap;

void				add_start_lst(t_file **hall, t_file *elem);
t_salle				*find_flag(t_salle *room, char *str);
void				print_lst(t_file *lst);
t_file				*file_new(char *str, char *flag);
void				add_end_lst(t_file **str, t_file *elem);
t_salle				*new_hall(char *name, char *flag, t_salle *next, int id);
int					verif_hall_tun(char *str);
t_salle				*config(t_file *hall, t_file *tunnel);
void				assign_tun(t_salle *room, t_file *tunnel, int halllen);
t_salle				*init_map(void);
int					lst_len(t_file *lst);
t_salle				*p_lst(t_salle *room, char *str);
int					id_lst(t_salle *room, char *str);
int					salle_len(t_salle *room);

#endif
