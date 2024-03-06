/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:21:48 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/05 14:01:20 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//O_CREAT will create the file if it doesn't exist.
//O_TRUNC will truncate the file to zero length if it already exists.
//O_RDWR indicates that the file will be opened for both reading and writing
int	main(int ac, char **av, char **ep)
{
	t_data	data;

	ac_check(ac);
	data.fd_outfile = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	fd_check(data.fd_outfile, ERR_OUTFILE);
	data.fd_infile = open(av[1], O_RDONLY);
	fd_check(data.fd_infile, ERR_INFILE);
	if (pipe(data.pipe_tube) < 0)
	{
		perror(ERR_PIPE);
		exit (1);
	}
	malloc_data(&data, av, ep);
	init_forks(&data, ep);
	free_data(&data);
}
//https://www.geeksforgeeks.org/pipe-system-call/
