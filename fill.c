/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:33:22 by mgena             #+#    #+#             */
/*   Updated: 2019/11/19 19:51:50 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <sys/stat.h>
#include <stdlib.h>

void add_list_dir(struct dirent *entry, t_list_dir **lst, t_flags flags)
{
	t_list_dir *newlst;
	t_list_dir *current;

	int i = 0;
	current = *lst;
	newlst = ft_make_lst(entry);
	if (flags.time_mod == 1 && flags.no_sort == 0)
		lst_add_mod(lst, newlst);
	else if (flags.time_acc == 1 && flags.no_sort == 0)
		lst_add_acc(lst, newlst);
	else if (flags.no_sort == 1)
		lst_add(lst, newlst);
	if (current == NULL)
		*lst = newlst;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = newlst;
	}
}


