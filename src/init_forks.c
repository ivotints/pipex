/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:47 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/05 12:12:43 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_forks(t_data *data, char **ep)
{
	data->child1_pid = fork();
	if (data->child1_pid < 0)
	{
		perror("Fork");
		exit (1);
	}
	if (data->child1_pid == CHILD)
		child_program1(*data, ep);
	data->child2_pid = fork();
	if (data->child2_pid < 0)
	{
		perror("Fork");
		exit (1);
	}
	if (data->child2_pid == CHILD)
		child_program2(*data, ep);
}
