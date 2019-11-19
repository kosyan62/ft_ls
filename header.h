/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:58:56 by mgena             #+#    #+#             */
/*   Updated: 2019/11/19 18:02:14 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_HEADER_H
# define FT_LS_HEADER_H

# include <dirent.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct		s_flags
{
	unsigned int	recursive	: 1;
	unsigned int	large		: 1;
	unsigned int	all			: 1;
	unsigned int	reverse		: 1;
	unsigned int	time_mod	: 1;
	unsigned int	time_acc	: 1;
	unsigned int	one			: 1;
	unsigned int	no_sort		: 1;
	unsigned int	dir_to_file	: 1;
	unsigned int	all_no_host	: 1;
	unsigned int	colour		: 1;
}					t_flags;

typedef struct		s_list_dir
{
	char *data;
	int type;
	struct s_list_dir *next;
	mode_t secure;
	uid_t mast_id;
	nlink_t links;
	struct timespec acc;
	struct timespec mod;
	off_t size;
} t_list_dir;

void	ft_ls(char *argv, t_flags flags);
void add_list_dir(struct dirent *entry, t_list_dir **lst, t_flags flags);
t_list_dir	*ft_make_lst(struct dirent *content);
void	ft_recursive(char *array, t_flags flags, char *end);


#endif
