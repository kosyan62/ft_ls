/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:16:32 by mgena             #+#    #+#             */
/*   Updated: 2020/01/03 19:18:30 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		lst_add_acc(t_list_dir **lst, t_list_dir *newlst)
{
	t_list_dir *current;

	current = *lst;
	if (current == NULL)
		*lst = newlst;
	else
	{
		while (current->next && (current->next->acc.tv_nsec > newlst->acc.tv_nsec))
			current = current->next;
		while (current->next && current->next->acc.tv_nsec == newlst->acc.tv_nsec &&
			   ft_strcmp(current->next->data, newlst->data) < 0)
			current = current->next;
		ft_pop_lst(&current, newlst);
	}
}
