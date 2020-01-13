/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:33:22 by mgena             #+#    #+#             */
/*   Updated: 2020/01/13 16:59:49 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/header.h"
#include <sys/stat.h>
#include <stdlib.h>

void	add_list(t_list_dir **lst, t_flags flags, char *path, char *name)
{
	t_list_dir *newlst;

	newlst = new_lst(path, name);
	if (!newlst)
		return ;
	if (flags.time == 1 && flags.no_sort == 0)
	{
		if (flags.time_acc == 1 && flags.no_sort == 0)
			lst_time_access_sort(lst, newlst);
		else
			lst_time_mod_sort(lst, newlst);
	}
	else if (flags.no_sort == 1)
		lst_no_sort(lst, newlst);
	else
		lst_abcsort(lst, newlst);
}

void	fill_lst(struct stat buf, t_list_dir *newlist)
{
	newlist->blocks = buf.st_blocks;
	newlist->type = buf.st_mode;
	newlist->next = NULL;
	newlist->acc = buf.st_atimespec;
	newlist->mod = buf.st_mtimespec;
	newlist->links = buf.st_nlink;
	newlist->mast_id = buf.st_uid;
	newlist->group_ud = buf.st_gid;
	newlist->size = buf.st_size;
}
