/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:30:27 by mgena             #+#    #+#             */
/*   Updated: 2020/02/03 16:58:23 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../includes/header.h"

void	print_ls_files_inside(t_list_dir *head, t_flags flags)
{
	if (flags.large)
	{
		if (flags.all == 1)
			print_more(*head, flags);
		else
		{
			if (head->name[0] != '.')
				print_more(*head, flags);
		}
	}
	else
	{
		if (flags.all == 1)
			ft_printf("%s\n", head->name);
		else
		{
			if (head->name[0] != '.')
				ft_printf("%s\n", head->name);
		}
	}
}

void	print_ls_files_only(t_list_dir *head, t_flags flags)
{
	while (head)
	{
		if (!S_ISDIR(head->type))
			print_ls_files_inside(head, flags);
		head = head->next;
	}
	ft_printf("\n");
}

void	print_ls_directories(t_list_dir *head, t_flags flags)
{
	while (head)
	{
		if (S_ISDIR(head->type))
		{
			ft_printf("%s:\n", head->name);
			ls_dir(head->name, flags);
		}
		head = head->next;
	}
}

void	mult_args(int argc, char **argv, t_flags flags)
{
	int			i;
	t_list_dir	*head;

	i = 1;
	head = NULL;
	while (i != argc)
	{
		add_list(&head, flags, ".", argv[i]);
		i++;
	}
	print_ls_files_only(head, flags);
	print_ls_directories(head, flags);
}
