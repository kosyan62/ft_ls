/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:08:21 by mgena             #+#    #+#             */
/*   Updated: 2019/11/19 18:18:14 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_recursive(char *cur, t_flags flags, char *end)
{
	char *ptr;
	ptr = ft_strdup(cur);
	ptr = ft_strjoin(cur, "/");
	ptr = ft_strjoin(ptr, end);
	printf("%s:\n", ptr);
	ft_ls(ptr, flags);
}

void print_files(t_list_dir *head, t_flags flags)
{
	while (head)
	{
		if (flags.all == 1)
		printf("%s\n", head->data);
		else
		{
			if (head->data[0] != '.')
				printf("%s\n", head->data);
		}
		head = head->next;
	}
	printf("\n");
}

void	ft_ls(char *array, t_flags flags)
{
	DIR *dir;
	struct dirent *entry;
	t_list_dir *head;

	head = NULL;
	dir = opendir(array);
	while ((entry = readdir(dir)) != NULL)
	{
		add_list_dir(entry, &head, flags);
	}
	print_files(head, flags);
	if (flags.recursive == 1)
	{
		while (head)
		{
			if (head->type == 4 && *(head->data) != '.')
				ft_recursive(array, flags, head->data);
			head = head->next;
		}
	}
}
