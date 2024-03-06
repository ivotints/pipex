/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:13:29 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/05 12:13:37 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// child will enter this function and die there too.
void	child_program1(t_data data, char **ep)
{
	dup2(data.pipe_tube[1], 1);
	close(data.pipe_tube[0]);
	dup2(data.fd_infile, 0);
	execve(data.cmd_path1, data.cmd_and_args1, ep);
}
//dup2 will close fd-1 of that program and open it again, but it will refer
//not to std_out but to write-part of pipe_tube
//we will not read anything from the pipe, so we close it.
//dup2 will close fd-0 of that programm and reopen it but not for
//reading from std_in, but for reading input from the fd_infile.

//dup2 redirect input for the command to the pipe_tube[0]
//we will not write anything to the pipe, so we close it.
//result of the command will be writen in outfile
void	child_program2(t_data data, char **ep)
{
	dup2(data.pipe_tube[0], 0);
	close(data.pipe_tube[1]);
	dup2(data.fd_outfile, 1);
	execve(data.cmd_path2, data.cmd_and_args2, ep);
}
