/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:08:21 by mgena             #+#    #+#             */
/*   Updated: 2020/01/08 15:35:45 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_recursive(char *cur, t_flags flags, char *end)
{
	char *ptr;
	ptr = ft_strdup(cur);
	ptr = ft_strjoin(ptr, "/");
	ptr = ft_strjoin(ptr, end);
	printf("%s:\n", ptr);
	ft_ls(ptr, flags);
}

void print_files(t_list_dir *head, t_flags flags)
{
	while (head)
	{
		if (flags.all == 1)
		printf("%s\n", head->name);
		else
		{
			if (head->name[0] != '.')
				printf("%s\n", head->name);
		}
		head = head->next;
	}
	printf("\n");
}


void print_files_large(t_list_dir *head, t_flags flags)
{
	while (head)
	{
		if (flags.all == 1)
			printf("%s\n", head->name);
		else
		{
			if (head->name[0] != '.')
				print_more(*head, flags);
		}
		head = head->next;
	}
	printf("\n");
}

void	ft_ls(char *array, t_flags flags)
{
	DIR *dir;
	struct dirent *entry;
	struct stat buf;
	t_list_dir *head;

	head = NULL;

	lstat(array, &buf);
	if (S_ISDIR(buf.st_mode))
	{
		dir = opendir(array);
		if (!dir)
		{
			printf("error open dir");
			exit(1);
		}
		while ((entry = readdir(dir)) != NULL)
		{
			add_list_dir(entry, &head, flags, array);
		}
		closedir(dir);
	}
	else
		add_list_file(buf, &head, array);
	if (flags.large == 1)
		print_files_large(head, flags);
	else
		print_files(head, flags);
	if (flags.recursive == 1)
	{
		while (head)
		{
			if (S_ISDIR(head->type) && *(head->name) != '.')
				ft_recursive(array, flags, head->name);
			head = head->next;
		}
	}
}
