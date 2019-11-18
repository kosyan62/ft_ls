/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:58:56 by mgena             #+#    #+#             */
/*   Updated: 2019/11/18 20:13:16 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_HEADER_H
# define FT_LS_HEADER_H

typedef struct		s_flags
{
	unsigned int	recursive	: 1;
	unsigned int	large		: 1;
	unsigned int	all			: 1;
	unsigned int	reverse		: 1;
	unsigned int	time		: 1;
	unsigned int	access_time	: 1;
	unsigned int	no_sort		: 1;
	unsigned int	dir_to_file	: 1;
}					t_flags;

typedef struct		s_list_dir
{
	char *data;
	int type;
	struct s_list_dir *next;
} t_list_dir;

# include <dirent.h>
# include "libft/libft.h"

void	ft_ls(int argc, char **argv, t_flags flags);
void	add_list_dir(struct dirent *entry, t_list_dir **lst);
t_list_dir	*ft_lstnew_dir(struct dirent *content);
void	ft_recursive(int argc, char **array, t_flags flags);


#endif
