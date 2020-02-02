/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:24:08 by mgena             #+#    #+#             */
/*   Updated: 2020/01/13 18:12:15 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <errno.h>

void	error_unexpected_flag(char ch)
{
	ft_printf("ls: illegal option -- %c\n", ch);
	ft_printf("usage: ls ");
	ft_printf("[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
	exit(1);
}

void	error_file(char *name)
{
	if (errno == ENOENT)
		ft_printf("ls: %s: No such file or directory\n", name);
	else if (errno == EACCES)
		ft_printf("ls: %s: Permission denied\n", name);
}
