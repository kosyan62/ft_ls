/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:33:22 by mgena             #+#    #+#             */
/*   Updated: 2020/01/03 20:17:36 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <sys/stat.h>
#include <stdlib.h>

void add_list_dir(struct dirent *entry, t_list_dir **lst, t_flags flags)
{
	t_list_dir *newlst;

	int i = 0;
	newlst = ft_make_lst(entry);
	if (flags.time_mod == 1 && flags.no_sort == 0)
		lst_add_mod(lst, newlst);
	else if (flags.time_acc == 1 && flags.no_sort == 0)
		lst_add_acc(lst, newlst);
	else if (flags.no_sort == 1)
	lst_add(lst, newlst);
	else
		lst_add_abcsort(lst, newlst);
}




