/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:33:22 by mgena             #+#    #+#             */
/*   Updated: 2020/02/02 15:04:37 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/header.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

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

void get_name_and_group(struct stat stat, t_list_dir *list)
{
	char			*name;
	char			*group;
	struct passwd	*src_name;
	struct group	*src_group;

	src_name = getpwuid(stat.st_uid);
	src_group = getgrgid(stat.st_gid);
	name = ft_strdup(src_name->pw_name);
	group = ft_strdup(src_group->gr_name);
	list->host = name;
	list->group = group;
}

void	fill_lst(struct stat buf, t_list_dir *newlist)
{
	newlist->blocks = buf.st_blocks;
	newlist->type = buf.st_mode;
	newlist->next = NULL;
	newlist->acc = buf.st_atimespec;
	newlist->mod = buf.st_mtimespec;
	newlist->links = buf.st_nlink;
	newlist->size = buf.st_size;
	get_name_and_group(buf, newlist);
}
