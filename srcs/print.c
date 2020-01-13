/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:58:13 by mgena             #+#    #+#             */
/*   Updated: 2020/01/13 16:17:30 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_total(t_list_dir *head, t_flags flags)
{
	int tot;

	tot = 0;
	while (head)
	{
		if (flags.all)
			tot += head->blocks;
		else
		{
			if (*head->name != '.')
				tot += head->blocks;
		}
		head = head->next;
	}
	ft_printf("total %d\n", tot);
}

void	print_ls_large(t_list_dir *head, t_flags flags)
{
	if (head->next)
		print_total(head, flags);
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
