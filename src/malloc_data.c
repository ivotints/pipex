/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:08:38 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/05 15:19:45 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//It recives all possible paths and only name of the command.
//Output of that function will be just path of that command or NULL.
static char	*find_cmd_path(char **paths, char *cmd_name)
{
	char	*temp;
	char	*cmd_with_path;

	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		cmd_with_path = ft_strjoin(temp, cmd_name);
		free(temp);
		if (access(cmd_with_path, 0) == 0)
			return (cmd_with_path);
		free(cmd_with_path);
		paths++;
	}
	return (NULL);
}

static char	*cmd_get_paths(char **ep)
{
	while (ft_strncmp("PATH=", *ep, 5))
		ep++;
	return (*ep + 5);
}

/*
	now in the cmd_paths_splited will be array like:
	/nfs/homes/ivotints/bin
	/usr/local/sbin
	/usr/local/bin
	/usr/sbin
	/usr/bin
	/sbin
	/bin
	/usr/games
	/usr/local/games
	/snap/bin
*/
static void	malloc_data2(t_data *data, char **av)
{
	data->cmd_and_args2 = ft_split(av[3], ' ');
	if (!data->cmd_and_args2)
	{
		free_arr_of_arr(data->cmd_paths_splited);
		free_arr_of_arr(data->cmd_and_args1);
		free(data->cmd_path1);
		error_msg("Malloc");
	}
	data->cmd_path2
		= find_cmd_path(data->cmd_paths_splited, data->cmd_and_args2[0]);
	if (!data->cmd_path2)
	{
		free_arr_of_arr(data->cmd_paths_splited);
		free_arr_of_arr(data->cmd_and_args1);
		free_arr_of_arr(data->cmd_and_args2);
		free(data->cmd_path1);
		error_msg(ERR_CMD2);
	}
}

//In cmd_and_args1 we have name of the cmd and each it's parameter in array
void	malloc_data(t_data *data, char **av, char **ep)
{
	data->cmd_paths_splited = ft_split(cmd_get_paths(ep), ':');
	if (!data->cmd_paths_splited)
		error_msg("Malloc");
	data->cmd_and_args1 = ft_split(av[2], ' ');
	if (!data->cmd_and_args1)
	{
		free_arr_of_arr(data->cmd_paths_splited);
		error_msg("Malloc");
	}
	data->cmd_path1
		= find_cmd_path(data->cmd_paths_splited, data->cmd_and_args1[0]);
	if (!data->cmd_path1)
	{
		free_arr_of_arr(data->cmd_paths_splited);
		free_arr_of_arr(data->cmd_and_args1);
		error_msg(ERR_CMD1);
	}
	malloc_data2(data, av);
}
