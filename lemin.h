/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:25:19 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/18 08:34:03 by cdrouet          ###   ########.fr       */
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
	int				pass;
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
	char			*name;
	struct s_path	*next;
}					t_path;

typedef struct		s_fourmi
{
	int				id;
	t_salle			*name;
	t_path			*path;
	struct s_fourmi	*next;
}					t_fourmis;

typedef struct		s_allp
{
	t_path			*path;
	int				nb_hall;
	struct s_allp	*next;
}					t_allp;

typedef struct		s_stap
{
	t_salle			*start;
	t_salle			*stop;
	int				nb_room;
}					t_stap;

int					verif_tri(t_allp *p);
void				tri_path(t_allp **p);
int					compar_path(t_path *p1, t_path *p2);
t_allp				*free_p(t_allp **elem);
void				free_elem(t_allp **al, t_allp *elem);
int					verif_bouchon(t_allp **all_path);
int					allp_len(t_allp *lst);
void				reinit_nb_hall(t_allp **all_path);
t_allp				*free_allp(t_allp **p, t_allp **start);
int					nb_next(t_stap *st, t_salle *room);
int					recur_path(t_stap *st, t_path **pat, t_salle **room, t_allp **pt);
void				destroy_last_path(t_path **p);
void				free_path(t_path **p);
int					search_index_low_path(t_path **path);
void				add_allp_end(t_allp **lst, t_allp *new);
int					path_len(t_path *p);
t_allp				*new_allp(t_path *p);
int					search_all_path(t_stap st, t_allp **pat, t_salle **room);
void				add_path_end(t_path **lst, t_path *new);
t_path				*new_path(char *name);
void				add_start_lst(t_file **hall, t_file *elem);
t_salle				*find_flag(t_salle *room, char *str);
void				print_lst(t_file *lst);
t_file				*file_new(char *str, char *flag);
void				add_end_lst(t_file **str, t_file *elem);
t_salle				*new_hall(char *name, char *flag, t_salle *next, int id);
int					verif_hall_tun(char *str);
t_salle				*config(t_file *hall, t_file *tunnel);
void				assign_tun(t_salle *room, t_file *tunnel, int halllen);
t_salle				*init_map(int nb_f);
int					lst_len(t_file *lst);
t_salle				*p_lst(t_salle *room, char *str);
int					id_lst(t_salle *room, char *str);
int					salle_len(t_salle *room);

#endif
