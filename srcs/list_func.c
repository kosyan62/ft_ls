/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:54:41 by mgena             #+#    #+#             */
/*   Updated: 2020/01/09 22:18:07 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/xattr.h>

t_list_dir *ft_make_lst(char *path, char *name)
{
	t_list_dir	*newlist;
	struct stat buf;
	char *fullname;

	newlist = (t_list_dir*)malloc(sizeof(t_list_dir));
	if (newlist == NULL)
		return (NULL);
	fullname = ft_strdup(path);
	fullname = ft_strjoin(fullname, "/");
	fullname = ft_strjoin(fullname, name);
	lstat(fullname, & buf);
	ft_strcpy(newlist->name, name);
	ft_strcpy(newlist->fullname, fullname);
	newlist->type = buf.st_mode;
	newlist->next = NULL;
	newlist->acc = buf.st_atimespec;
	newlist->mod = buf.st_mtimespec;
	newlist->birth = buf.st_birthtimespec;
	newlist->links = buf.st_nlink;
	newlist->mast_id = buf.st_uid;
	newlist->group_ud = buf.st_gid;
	newlist->size = buf.st_size;
	ft_strdel(&fullname);
	return (newlist);
}

void ft_pop_lst(t_list_dir **lst, t_list_dir *newlst)
{
	t_list_dir *current;
	t_list_dir *tmp;

	current = *lst;
	if (current->next == NULL)
		current->next = newlst;
	else
	{
		tmp = current->next;
		current->next = newlst;
		current = current->next;
		current->next = tmp;
	}
}

void	lst_add(t_list_dir **lst, t_list_dir *newlst)
{
	t_list_dir *current;

	current = *lst;
	if (current == NULL)
	*lst = newlst;
	else
	{
	while (current->next != NULL)
		current = current->next;
	current->next = newlst;
	}
}

void	lst_add_mod(t_list_dir **lst, t_list_dir *newlst)
{
	t_list_dir *current;

	current = *lst;
	if (current == NULL)
		*lst = newlst;
	else
	{
		while (current->next && (current->next->mod.tv_sec > newlst->mod.tv_sec))
			current = current->next;
		while (current->next && current->next->mod.tv_sec == newlst->mod.tv_sec &&
			   ft_strcmp(current->next->name, newlst->name) < 0)
			current = current->next;
		ft_pop_lst(&current, newlst);
	}
}

void lst_add_abcsort(t_list_dir **lst, t_list_dir *newlst)
{
	t_list_dir *current;

	current = *lst;
	if (current == NULL)
		*lst = newlst;
	else
	{
		while (current->next && ft_strcmp(current->next->name, newlst->name) < 0)
			current = current->next;
		ft_pop_lst(&current, newlst);
	}
}
