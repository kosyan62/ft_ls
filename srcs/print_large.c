/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:51:56 by mgena             #+#    #+#             */
/*   Updated: 2020/01/13 18:50:11 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <time.h>
#include <errno.h>

void	print_type(t_list_dir head)
{
	if (S_ISREG(head.type))
		ft_printf("-");
	else if (S_ISDIR(head.type))
		ft_printf("d");
	else if (S_ISCHR(head.type))
		ft_printf("c");
	else if (S_ISBLK(head.type))
		ft_printf("b");
	else if (S_ISFIFO(head.type))
		ft_printf("p");
	else if (S_ISLNK(head.type))
		ft_printf("l");
	else if (S_ISSOCK(head.type))
		ft_printf("s");
}

void	print_chmod(mode_t type, int bit, char ch)
{
	if (type & bit)
		ft_printf("%c", ch);
	else
		ft_printf("-");
}

void	print_exattr(t_list_dir head)
{
	acl_t		acl;
	acl_entry_t	entry;
	ssize_t		xattr;
	char		chr;

	acl = acl_get_link_np(head.fullname, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(head.fullname, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		chr = '@';
	else if (acl != NULL)
		chr = '+';
	else
		chr = ' ';
	ft_printf("%c", chr);
}

void	choose_chmod(t_list_dir head)
{
	print_chmod(head.type, S_IRUSR, 'r');
	print_chmod(head.type, S_IWUSR, 'w');
	print_chmod(head.type, S_IXUSR, 'x');
	print_chmod(head.type, S_IRGRP, 'r');
	print_chmod(head.type, S_IWGRP, 'w');
	print_chmod(head.type, S_IXGRP, 'x');
	print_chmod(head.type, S_IROTH, 'r');
	print_chmod(head.type, S_IWOTH, 'w');
	print_chmod(head.type, S_IXOTH, 'x');
	print_exattr(head);
}

void	print_more(t_list_dir head, t_flags flags)
{
	print_type(head);
	choose_chmod(head);
	ft_printf(" %1d", head.links);
	print_name_and_group(head, flags);
	ft_printf(" %4lld ", head.size);
	if (flags.time_acc)
		print_time(head.acc);
	else
		print_time(head.mod);
	ft_printf("%s", head.name);
	if (S_ISLNK(head.type))
		print_link(head);
	ft_printf("\n");
}
