/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:54:41 by mgena             #+#    #+#             */
/*   Updated: 2020/01/03 21:37:28 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "header.h"
#include <stdio.h>
#include <errno.h>

t_list_dir	*ft_make_lst(struct dirent *content)
{
	t_list_dir	*newlist;
	struct stat buf;

	stat(content->d_name, &buf);
	newlist = (t_list_dir*)malloc(sizeof(t_list_dir));
	if (newlist == NULL)
		return (NULL);
	newlist->data = ft_strdup(content->d_name);
	newlist->type = content->d_type;
	newlist->next = NULL;
	newlist->acc = buf.st_atimespec;
	newlist->mod = buf.st_mtimespec;
	newlist->links = buf.st_nlink;
	newlist->mast_id = buf.st_uid;
	newlist->secure = buf.st_mode;
	newlist->size = buf.st_size;
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
		while (current->next && (current->next->mod.tv_nsec > newlst->mod.tv_nsec))
			current = current->next;
		while (current->next && current->next->mod.tv_nsec == newlst->mod.tv_nsec &&
		ft_strcmp(current->next->data, newlst->data) < 0)
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
		while (current->next && ft_strcmp(current->next->data, newlst->data) < 0)
			current = current->next;
		ft_pop_lst(&current, newlst);
	}
}
