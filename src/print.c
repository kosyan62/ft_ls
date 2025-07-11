/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:58:13 by mgena             #+#    #+#             */
/*   Updated: 2020/02/03 17:16:31 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include "../includes/header.h"

void	print_ls_less(t_list_dir *head, t_flags flags)
{
	while (head)
	{
		if (flags.all == 1)
			ft_printf("%s\n", head->name);
		else
		{
			if (head->name[0] != '.')
				ft_printf("%s\n", head->name);
		}
		head = head->next;
	}
}

void	get_len_for_spaces(t_list_dir *head, t_flags *flags)
{
	int links;
	int name;
	int size;
	int group_len;

	links = ft_countdigits(head->links);
	size = ft_countdigits(head->size);
	name = ft_strlen(head->host);
	group_len = ft_strlen(head->group);
	if (links > flags->links_len)
		flags->links_len = links;
	if (size > flags->size_len)
		flags->size_len = size;
	if (name > flags->name_len)
		flags->name_len = name;
	if (name > flags->name_len)
		flags->name_len = name;
	if (group_len > flags->group)
		flags->group = group_len;
}

void	print_total(t_list_dir *head, t_flags *flags)
{
	int tot;

	tot = 0;
	while (head)
	{
		if (flags->all)
			tot += head->blocks;
		else
		{
			if (*head->name != '.')
				tot += head->blocks;
		}
		get_len_for_spaces(head, flags);
		head = head->next;
	}
	ft_printf("total %d\n", tot);
}

void	print_ls_large(t_list_dir *head, t_flags flags)
{
	if (head->next)
		print_total(head, &flags);
	while (head)
	{
		if (flags.all == 1)
			print_more(*head, flags);
		else
		{
			if (head->name[0] != '.')
				print_more(*head, flags);
		}
		head = head->next;
	}
}

void	print_ls(t_list_dir *head, t_flags flags)
{
	if (flags.large == 1)
		print_ls_large(head, flags);
	else
		print_ls_less(head, flags);
}
