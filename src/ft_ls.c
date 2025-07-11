/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:08:21 by mgena             #+#    #+#             */
/*   Updated: 2020/01/13 17:07:01 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_recursive(char *cur, t_flags flags, char *end)
{
	char *ptr;
	char *tmp;

	ptr = ft_strdup(cur);
	tmp = ft_strjoin(ptr, "/");
	ft_strdel(&ptr);
	ptr = ft_strjoin(tmp, end);
	ft_strdel(&tmp);
	ft_printf("\n%s:\n", ptr);
	ls_dir(ptr, flags);
	ft_strdel(&ptr);
}

void	recursive_begin(t_list_dir *head, t_flags flags, char *array)
{
	while (head)
	{
		if (S_ISDIR(head->type) && ft_strcmp((head->name), ".")
		&& ft_strcmp((head->name), ".."))
		{
			if (flags.all == 1)
				ft_recursive(array, flags, head->name);
			else
			{
				if (head->name[0] != '.')
					ft_recursive(array, flags, head->name);
			}
		}
		head = head->next;
	}
}

void	ls_dir(char *array, t_flags flags)
{
	DIR				*dir;
	struct dirent	*entry;
	t_list_dir		*head;
	t_list_dir		*tobefree;

	head = NULL;
	dir = opendir(array);
	if (!dir)
	{
		error_file(array);
		return ;
	}
	while ((entry = readdir(dir)) != NULL)
		add_list(&head, flags, array, entry->d_name);
	closedir(dir);
	if (!flags.no_sort && flags.reverse)
		reverse_list_dir(&head);
	print_ls(head, flags);
	tobefree = head;
	if (flags.recursive == 1)
		recursive_begin(head, flags, array);
	lst_dir_del(&tobefree);
}
