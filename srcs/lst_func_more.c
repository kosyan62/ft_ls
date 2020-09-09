/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:16:32 by mgena             #+#    #+#             */
/*   Updated: 2020/01/13 15:25:56 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	lst_time_access_sort(t_list_dir **lst, t_list_dir *newlst)
{
	t_list_dir *curr;

	curr = *lst;
	if (curr == NULL)
		*lst = newlst;
	else
	{
		while (curr->next && (curr->next->acc > newlst->acc))
			curr = curr->next;
		while (curr->next && curr->next->acc == newlst->acc &&
		ft_strcmp(curr->next->name, newlst->name) < 0)
			curr = curr->next;
		ft_pop_lst_aft(&curr, newlst);
		if (curr->next->acc > curr->acc
			|| (curr->next->acc == curr->acc &&
				ft_strcmp(curr->next->name, curr->name) < 0))
		{
			lst_swap(&curr);
			*lst = curr;
		}
	}
}

void	lst_dir_del(t_list_dir **lst)
{
	t_list_dir *next;

	next = (*lst);
	if (next)
		lst_dir_del(&next->next);
	free(*lst);
}

void	reverse_list_dir(t_list_dir **src)
{
	t_list_dir *current;
	t_list_dir *prev;
	t_list_dir *next;

	current = *src;
	prev = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*src = prev;
}

void	lst_swap(t_list_dir **lst)
{
	t_list_dir *tmp;
	t_list_dir *current;

	current = *lst;
	tmp = current->next;
	*lst = current->next;
	current->next = tmp->next;
	tmp->next = current;
}

void	lst_abcsort(t_list_dir **lst, t_list_dir *newlst)
{
	t_list_dir *curr;

	curr = *lst;
	if (curr == NULL)
		*lst = newlst;
	else
	{
		while (curr->next && ft_strcmp(curr->next->name, newlst->name) < 0)
			curr = curr->next;
		ft_pop_lst_aft(&curr, newlst);
	}
}
