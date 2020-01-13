/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:54:41 by mgena             #+#    #+#             */
/*   Updated: 2020/01/13 22:22:55 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/xattr.h>

char		*get_full_name(char *path, char *name)
{
	char *fullname;
	char tmp[1024];

	ft_strcpy(tmp, path);
	ft_strcat(tmp, "/");
	ft_strcat(tmp, name);
	fullname = ft_strdup(tmp);
	return (fullname);
}

t_list_dir	*new_lst(char *path, char *name)
{
	t_list_dir	*newlist;
	struct stat	buf;
	char		*fullname;

	newlist = (t_list_dir*)malloc(sizeof(t_list_dir));
	if (newlist == NULL)
		perror("malloc");
	fullname = get_full_name(path, name);
	if (lstat(fullname, &buf) < 0)
	{
		error_file(name);
		free(newlist);
		return (NULL);
	}
	ft_strcpy(newlist->name, name);
	ft_strcpy(newlist->fullname, fullname);
	fill_lst(buf, newlist);
	ft_strdel(&fullname);
	return (newlist);
}

void		ft_pop_lst_aft(t_list_dir **lst, t_list_dir *newlst)
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

void		lst_no_sort(t_list_dir **lst, t_list_dir *newlst)
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

void		lst_time_mod_sort(t_list_dir **lst, t_list_dir *newlst)
{
	t_list_dir *curr;

	curr = *lst;
	if (curr == NULL)
	{
		*lst = newlst;
		return ;
	}
	else
	{
		while (curr->next && (curr->next->mod.tv_sec > newlst->mod.tv_sec))
			curr = curr->next;
		while (curr->next && curr->next->mod.tv_sec == newlst->mod.tv_sec &&
			ft_strcmp(curr->next->name, newlst->name) < 0)
			curr = curr->next;
		ft_pop_lst_aft(&curr, newlst);
		if (curr->next->mod.tv_sec > curr->mod.tv_sec
			|| (curr->next->mod.tv_sec == curr->mod.tv_sec &&
				ft_strcmp(curr->next->name, curr->name) < 0))
		{
			lst_swap(&curr);
			*lst = curr;
		}
	}
}
