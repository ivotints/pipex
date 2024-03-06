/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:10:11 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/05 12:10:41 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_arr_of_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

//We wait while all chindrens will die and than parent should clean after them
void	free_data(t_data *data)
{
	close(data->pipe_tube[0]);
	close(data->pipe_tube[1]);
	waitpid(data->child1_pid, NULL, 0);
	waitpid(data->child2_pid, NULL, 0);
	close(data->fd_infile);
	close(data->fd_outfile);
	free_arr_of_arr(data->cmd_paths_splited);
	free_arr_of_arr(data->cmd_and_args1);
	free_arr_of_arr(data->cmd_and_args2);
	free(data->cmd_path1);
	free(data->cmd_path2);
	exit (0);
}
