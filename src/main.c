/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:31:21 by mgena             #+#    #+#             */
/*   Updated: 2020/02/03 16:22:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "../includes/header.h"

t_flags		make_flag_more(t_flags res, char *string)
{
	if (*string == 'u')
		res.time_acc |= 1;
	else if (*string == 'G')
		res.colour |= 1;
	else if (*string == 'g')
		res.all_no_host |= 1;
	else if (*string == 'f')
	{
		res.no_sort |= 1;
		res.all |= 1;
	}
	else
		error_unexpected_flag(*string);
	res.links_len = 0;
	res.name_len = 0;
	res.size_len = 0;
	res.group = 0;
	return (res);
}

t_flags		make_flag(t_flags res, char *string)
{
	while (*string != 0)
	{
		if (*string == 'R')
			res.recursive |= 1;
		else if (*string == 'r')
			res.reverse |= 1;
		else if (*string == 'l')
			res.large |= 1;
		else if (*string == 'a')
			res.all |= 1;
		else if (*string == 't')
			res.time |= 1;
		else if (*string == '1')
			res.one |= 1;
		else
			res = make_flag_more(res, string);
		string++;
	}
	return (res);
}

t_flags		fill_flags(char *string)
{
	static t_flags	res;
	static _Bool	was_dbl_dsh;

	if (ft_strcmp(string, "--") == 0)
	{
		was_dbl_dsh = 1;
		return (res);
	}
	else if (ft_strcmp(string, "-") == 0 || was_dbl_dsh == 1)
		error_file(string);
	string++;
	res = make_flag(res, string);
	return (res);
}

void		chose_arg_format(char *name, t_flags flags)
{
	t_list_dir *head;

	head = new_lst(".", name);
	if (head == NULL)
		return ;
	if (S_ISDIR(head->type))
		ls_dir(name, flags);
	else
		print_ls(head, flags);
}

int			main(int argc, char **argv)
{
	t_flags flags;

	while (argc != 1 && *argv[1] == '-')
	{
		flags = fill_flags(argv[1]);
		argv++;
		argc -= 1;
	}
	if (argc == 1)
		ls_dir(".", flags);
	else if (argc == 2)
	{
		chose_arg_format(argv[1], flags);
	}
	else
	{
		mult_args(argc, argv, flags);
	}
	return (0);
}
