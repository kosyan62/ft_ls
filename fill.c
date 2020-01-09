/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:33:22 by mgena             #+#    #+#             */
/*   Updated: 2020/01/09 18:42:48 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <sys/stat.h>
#include <stdlib.h>

void add_list_dir(struct dirent *entry, t_list_dir **lst, t_flags flags, char *path)
{
	t_list_dir *newlst;

	newlst = ft_make_lst(path, entry->d_name);
	if (flags.time == 1 && flags.no_sort == 0)
	{
		if (flags.time_acc == 1 && flags.no_sort == 0)
			lst_add_acc(lst, newlst);
		else
			lst_add_mod(lst, newlst);
	}
	else if (flags.no_sort == 1)
	lst_add(lst, newlst);
	else
		lst_add_abcsort(lst, newlst);
}

void add_list_file(struct stat buf, t_list_dir *(*lst), char *array)
{

	(*lst) = (t_list_dir*)malloc(sizeof(t_list_dir));
	if ((*lst) == NULL)
		exit(0);
	ft_strcpy(((*lst))->name, array);
	((*lst))->type = buf.st_mode;
	(*lst)->next = NULL;
	(*lst)->acc = buf.st_atimespec;
	(*lst)->mod = buf.st_mtimespec;
	(*lst)->birth = buf.st_birthtimespec;
	(*lst)->links = buf.st_nlink;
	(*lst)->mast_id = buf.st_uid;
	(*lst)->group_ud = buf.st_gid;
	(*lst)->size = buf.st_size;
}




