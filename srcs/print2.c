/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:14:26 by mgena             #+#    #+#             */
/*   Updated: 2020/02/02 15:08:58 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include "../includes/header.h"
#include <time.h>

void	print_name_and_group(t_list_dir head, t_flags flags)
{
	if (flags.all_no_host)
		head.host = 0;
	ft_printf(" %*s  %-*s", flags.name_len, head.host, flags.group + 1, head.group);
	ft_strdel(&head.host);
	ft_strdel(&head.group);
}

void	print_time(struct timespec time)
{
	char timestr[25];

	ft_strcpy(timestr, ctime(&time.tv_sec));
	ft_strcpy(timestr, &timestr[4]);
	timestr[12] = '\0';
	ft_printf("%s ", timestr);
}

void	print_link(t_list_dir dir)
{
	struct stat	buf;
	char		str[1024];
	int			len;

	lstat(dir.fullname, &buf);
	len = readlink(dir.fullname, str, 1024);
	str[len] = 0;
	ft_printf(" -> %s", str);
}
