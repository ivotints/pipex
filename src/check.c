/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:07:38 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/05 12:07:52 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

int	error_msg(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error. ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	exit(1);
}

void	fd_check(int fd, char *str)
{
	if (fd < 0)
	{
		perror(str);
		exit (0);
	}
}

void	ac_check(int ac)
{
	if (ac < 5)
		error_msg(ERR_FEW_ARGS);
	if (ac > 5)
		error_msg(ERR_LOTS_ARGS);
}
