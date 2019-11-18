/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:54:41 by mgena             #+#    #+#             */
/*   Updated: 2019/11/18 21:07:04 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "header.h"
#include <stdio.h>

t_list_dir	*ft_lstnew_dir(struct dirent *content)
{
	t_list_dir	*newlist;

	newlist = (t_list_dir*)malloc(sizeof(t_list_dir));
	if (newlist == NULL)
		return (NULL);
	newlist->data = content->d_name;
	newlist->type = content->d_type;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstdel_dir(t_list_dir **ptr)
{
	if ((*ptr)->next != NULL)
		*ptr = (*ptr)->next;
	free(ptr);
	printf("a\n");
}
