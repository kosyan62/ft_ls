/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:51:56 by mgena             #+#    #+#             */
/*   Updated: 2020/01/03 22:11:27 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void print_type(t_list_dir head)
{
	if (S_ISREG(head.type))
		printf("-");
	else if (S_ISDIR(head.type))
		printf("d");
	else if (S_ISCHR(head.type))
		printf("c");
	else if (S_ISBLK(head.type))
		printf("b");
	else if (S_ISFIFO(head.type))
		printf("p");
	else if (S_ISLNK(head.type))
		printf("l");
	else if (S_ISSOCK(head.type))
		printf("s");
}

void print_chmod(int type)
{
	if (S_ISU)
}

void	print_more(t_list_dir head)
{
	print_type(head);
	print_chmod(head.type)


}