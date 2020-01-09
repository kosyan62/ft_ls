/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:51:56 by mgena             #+#    #+#             */
/*   Updated: 2020/01/06 16:16:28 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

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

void	print_chmod(mode_t type, int bit, char ch)
{
	if (type & bit)
		printf("%c", ch);
	else
		printf("-");
}
void choose_chmod(int type)
{
	print_chmod(type, S_IRUSR, 'r');
	print_chmod(type, S_IWUSR, 'w');
	print_chmod(type, S_IXUSR, 'x');
	print_chmod(type, S_IRGRP, 'r');
	print_chmod(type, S_IWGRP, 'w');
	print_chmod(type, S_IXGRP, 'x');
	print_chmod(type, S_IROTH, 'r');
	print_chmod(type, S_IWOTH, 'w');
	print_chmod(type, S_IXOTH, 'x');
}

void	print_name_and_group(t_list_dir head)
{
	char *name;
	char *group;
	struct passwd *src_name;
	struct group *src_group;

	src_name = getpwuid(head.mast_id);
	src_group = getgrgid(head.group_ud);
	name = ft_strdup(src_name->pw_name);
	group = ft_strdup(src_group->gr_name);
	printf("%s  %s", name, group);
	ft_strdel(&name);
	ft_strdel(&group);
}

void	print_time(struct timespec time)
{
	char timestr[25];

	ft_strcpy(timestr,ctime(&time.tv_sec));
	ft_strcpy(timestr, &timestr[4]);
	timestr[12] = '\0';
	printf("%s ", timestr);

}

void	print_more(t_list_dir head, t_flags flags)
{
	print_type(head);
	choose_chmod(head.type);
	printf("%5d ", head.links);
	print_name_and_group(head);
	printf("%7lld ", head.size);
	if (flags.time_acc)
		print_time(head.acc);
	else
		print_time(head.mod);
	printf("%s\n", head.name);
}