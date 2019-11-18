/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:22:29 by mgena             #+#    #+#             */
/*   Updated: 2019/11/18 22:05:38 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>


t_flags fill_flags(char *string)
{
	t_flags res;

	while (*string!= 0)
	{
		if (*string == 'R')
			res.recursive = 1;
		if (*string == 'r')
			res.reverse = 1;
		if (*string == 'l')
			res.large = 1;
		if (*string == 'a')
			res.all = 1;
		if (*string == 't')
			res.time = 1;
		string++;
	}
	return (res);
}

int main(int argc, char **argv)
{
	t_flags flags;
	int i;
	char **array;

	array = argv + 1;
	i = 1;
	if (argc != 1)
	{
		if (**array == '-')
		{
			flags = fill_flags(argv[1]);
			array++;
			argc -= 1;
		}
	}
	ft_ls(argc, array, flags);
	return 0;
}

