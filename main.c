/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:22:29 by mgena             #+#    #+#             */
/*   Updated: 2020/01/03 20:13:29 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

t_flags		fill_flags(char *string)
{
	t_flags res;

	while (*string != 0)
	{
		if (*string == 'R')
			res.recursive |= 1;
		if (*string == 'r')
			res.reverse |= 1;
		if (*string == 'l')
			res.large |= 1;
		if (*string == 'a')
			res.all |= 1;
		if (*string == 't')
			res.time_mod |= 1;
		if (*string == '1')
			res.one |= 1;
		if (*string == 'u')
			res.time_acc |= 1;
		if (*string == 'G')
			res.colour |= 1;
		if (*string == 'g')
			res.all_no_host |= 1;
		if (*string == 'd')
			res.dir_to_file |= 1;
		if (*string == 'f')
		{
			res.no_sort |= 1;
			res.all |= 1;
		}
		string++;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	t_flags flags;
	int i;

	i = 1;
	if (argc != 1)
	{
		if (*argv[1] == '-')
		{
			flags = fill_flags(argv[1]);
			argv++;
			argc -= 1;
		}
	}
	if (argc == 1)
		ft_ls(".", flags);
	else if (argc == 2)
		ft_ls(argv[1], flags);
	else
	{
		while (i != argc)
		{
			printf("%s:\n", argv[i]);
			ft_ls(argv[i], flags);
			i++;
		}
	}
	return 0;
}

