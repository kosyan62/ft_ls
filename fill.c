/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:33:22 by mgena             #+#    #+#             */
/*   Updated: 2019/11/18 20:18:54 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <stdlib.h>

void add_list_dir(struct dirent *entry, t_list_dir **lst)
{
	t_list_dir *newlst;
	t_list_dir *current;

	int i = 0;
	current = *lst;
	newlst = ft_lstnew_dir(entry);
	if (current == NULL)
		*lst = newlst;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = newlst;
	}
}


