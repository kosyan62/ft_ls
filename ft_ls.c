/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:08:21 by mgena             #+#    #+#             */
/*   Updated: 2019/11/18 22:18:01 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>



void	ft_ls(int argc, char **array, t_flags flags)
{
	DIR *dir;
	struct dirent *entry;
	t_list_dir *head;
	t_list_dir *tmp;

	head = NULL;
	if (argc == 1)
	{
		dir = opendir(".");
		while ((entry = readdir(dir)) != NULL)
		{
				add_list_dir(entry, &head);

		}
	}
	else if (argc == 2)
	{
		dir = opendir(*array);
		while ((entry= readdir(dir)) != NULL)
		{
			add_list_dir(entry, &head);
		}
	}
	tmp = head;
	while (head->next)
	{
		printf("%s - [%d]\n", (*head).data, (*head).type);
		head = head->next;
	}
	if (flags.recursive == 1)
		ft_recursive(argc, **array, flags);
}
