/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:54:41 by mgena             #+#    #+#             */
/*   Updated: 2019/11/19 19:29:31 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "header.h"
#include <stdio.h>
#include <errno.h>

t_list_dir	*ft_make_lst(struct dirent *content)
{
	t_list_dir	*newlist;
	struct stat buf;

	lstat(content->d_name, &buf);
	newlist = (t_list_dir*)malloc(sizeof(t_list_dir));
	if (newlist == NULL)
		return (NULL);
	newlist->data = ft_strdup(content->d_name);
	newlist->type = content->d_type;
	newlist->next = NULL;
	newlist->acc = buf.st_mtimespec;
	newlist->mod = buf.st_mtimespec;
	newlist->links = buf.st_nlink;
	newlist->mast_id = buf.st_uid;
	newlist->secure = buf.st_mode;
	newlist->size = buf.st_size;
	return (newlist);
}
