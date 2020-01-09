/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:58:56 by mgena             #+#    #+#             */
/*   Updated: 2020/01/09 22:15:42 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_HEADER_H
# define FT_LS_HEADER_H

# include <dirent.h>
# include "../srcs/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_flags
{
	unsigned int	recursive	: 1;
	unsigned int	large		: 1;
	unsigned int	all			: 1;
	unsigned int	reverse		: 1;
	unsigned int	time	: 1;
	unsigned int	time_acc	: 1;
	unsigned int	one			: 1;
	unsigned int	no_sort		: 1;
	unsigned int	dir_to_file	: 1;
	unsigned int	all_no_host	: 1;
	unsigned int	colour		: 1;
}					t_flags;

typedef struct		s_list_dir
{
	char name[1024];
	char fullname[1024];
	mode_t type;
	struct s_list_dir *next;
	uid_t mast_id;
	gid_t group_ud;
	nlink_t links;
	struct timespec acc;
	struct timespec mod;
	struct timespec birth;
	off_t size;
} t_list_dir;

void		ft_ls_lulz(char *array, t_flags flags);
void		print_more(t_list_dir head, t_flags flags);
void add_list_dir(struct dirent *entry, t_list_dir **lst, t_flags flags, char *path);
void add_list_file(struct stat buf, t_list_dir **lst, char *array);
t_list_dir *ft_make_lst(char *path, char *name);
void		ft_recursive(char *array, t_flags flags, char *end);
void		ft_pop_lst(t_list_dir **lst, t_list_dir *newlst);
void		lst_add_mod(t_list_dir **lst, t_list_dir *newlst);
void		lst_add(t_list_dir **lst, t_list_dir *newlst);
void		lst_add_abcsort(t_list_dir **lst, t_list_dir *newlst);
void		lst_add_acc(t_list_dir **lst, t_list_dir *newlst);

#endif
