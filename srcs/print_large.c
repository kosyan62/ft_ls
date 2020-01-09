/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:51:56 by mgena             #+#    #+#             */
/*   Updated: 2020/01/09 22:59:15 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <sys/stat.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>

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

void print_exattr(t_list_dir head)
{
	ssize_t buflen;
//	ssize_t keylen;
//	ssize_t vallen;
//	char *buf;
//	char *key;
//	char *val;

	buflen = listxattr(head.fullname, NULL, 0, XATTR_NOFOLLOW);
	if (buflen == 0)
	{
		printf("-");
		return ;
	}
	else if (buflen < 0)
	{
		if (errno == EACCES)
			printf("+");
		else
		{
			perror("listxattr: ");
			exit(0);
		}
	}
	else
		printf("@");
	//TODO make "+" connected with ACL
//	buf = malloc(buflen);
//	buflen = listxattr(head.fullname, buf, buflen, 0);
//	key = buf;
//	while (buflen > 0)
//	{
//		printf("%s: ", key);
//		vallen = getxattr(head.fullname, key, NULL, 0, 0, 0);
//		if (vallen == -1)
//			perror("getxattr");
//		if (vallen > 0) {
//			val = malloc(vallen + 1);
//			if (val == NULL) {
//				perror("malloc");
//				exit(EXIT_FAILURE);
//			}
//			vallen = getxattr(head.fullname, key, val, vallen, 0, 0);
//			if (vallen == -1)
//				perror("getxattr");
//			else {
//				val[vallen] = 0;
//				printf("%s", val);
//			}
//			free(val);
//		} else if (vallen == 0)
//			printf("<нет значения>");
//		printf("\n");
//		keylen = ft_strlen(key) + 1;
//		buflen -= keylen;
//		key += keylen;
//	}
//	free(buf);
}

void choose_chmod(t_list_dir head)
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

void print_link(t_list_dir dir)
{
	struct stat buf;
	char str[1024];
	int len;

	lstat(dir.fullname, &buf);
	len = readlink(dir.fullname, str, 1024);
	str[len] = 0;
	printf(" -> %s", str);
}

void	print_more(t_list_dir head, t_flags flags)
{
	print_type(head);
	choose_chmod(head);
	printf("%5d ", head.links);
	print_name_and_group(head);
	printf("%7lld ", head.size);
	if (flags.time_acc)
		print_time(head.acc);
	else
		print_time(head.mod);
	printf("%s", head.name);
	if (S_ISLNK(head.type))
		print_link(head);
	printf("\n");
}