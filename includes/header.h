/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:58:56 by mgena             #+#    #+#             */
/*   Updated: 2020/02/02 14:40:54 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_HEADER_H
# define FT_LS_HEADER_H

#ifdef __APPLE__
#ifndef st_mtime
#define st_mtime st_mtimespec.tv_sec
#endif
#endif

# include <dirent.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_flags
{
	unsigned int	recursive	: 1;
	unsigned int	large		: 1;
	unsigned int	all			: 1;
	unsigned int	reverse		: 1;
	unsigned int	time	: 1;
	unsigned int	time_acc	: 1;
	unsigned int	one			: 1;
	unsigned int	no_sort		: 1;
	unsigned int	all_no_host	: 1;
	unsigned int	colour		: 1;
	int	links_len;
	int name_len;
	int	size_len;
	int group;

}				t_flags;

typedef struct	s_list_dir
{
	char				name[1024];
	char				fullname[1024];
	blkcnt_t			blocks;
	mode_t				type;
	struct s_list_dir	*next;
	char				*host;
	char				*group;
	nlink_t				links;
	time_t				acc;
	time_t				mod;
	off_t				size;

}				t_list_dir;

void			ls_dir(char *array, t_flags flags);
void			mult_args(int argc, char **argv, t_flags flags);
void			print_ls(t_list_dir *head, t_flags flags);
void			print_more(t_list_dir head, t_flags flags);
void			add_list(t_list_dir **lst, t_flags fl, char *path, char *name);
void			lst_dir_del(t_list_dir **lst);
void			lst_swap(t_list_dir **current);
void			ft_recursive(char *array, t_flags flags, char *end);
void			ft_pop_lst_aft(t_list_dir **lst, t_list_dir *newlst);
void			lst_time_mod_sort(t_list_dir **lst, t_list_dir *newlst);
void			lst_no_sort(t_list_dir **lst, t_list_dir *newlst);
void			lst_abcsort(t_list_dir **lst, t_list_dir *newlst);
void			lst_time_access_sort(t_list_dir **lst, t_list_dir *newlst);
void			print_ls_large(t_list_dir *head, t_flags flags);
void			print_ls_less(t_list_dir *head, t_flags flags);
void			reverse_list_dir(t_list_dir **src);
void			error_unexpected_flag(char ch);
void			error_file(char *name);
t_list_dir		*new_lst(char *path, char *name);
void			print_name_and_group(t_list_dir head, t_flags flags);
void			print_time(time_t time);
void			print_link(t_list_dir dir);
void			fill_lst(struct stat buf, t_list_dir *newlist);

#endif
