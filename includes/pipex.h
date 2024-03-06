/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:11:59 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/05 12:57:35 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//to write, read, close, access, pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

//malloc, free, exit
# include <stdlib.h>

//open, unlink
# include <fcntl.h>

//waitpid, wait
# include <sys/wait.h>

//strerror
# include <string.h>

//perror
# include <stdio.h>

//Colors
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define WHITE "\033[1;37m"

//Errors
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_FEW_ARGS "Small amount of arguments.\033[0m Please indicate:\n\
infile \"cmd1\" \"cmd2\" outfile"
# define ERR_LOTS_ARGS "Large amount of arguments.\033[0m Please indicate:\n\
infile \"cmd1\" \"cmd2\" outfile"
# define ERR_PIPE "Pipe"
# define ERR_CMD1 "First command not found"
# define ERR_CMD2 "Second command not found"

//some defenitions
# define CHILD 0

typedef struct s_data
{
	int		fd_infile;
	int		fd_outfile;
	char	**cmd_paths_splited;
	pid_t	child1_pid;
	pid_t	child2_pid;
	int		pipe_tube[2];
	char	**cmd_and_args1;
	char	**cmd_and_args2;
	char	*cmd_path1;
	char	*cmd_path2;

}				t_data;

//functions
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);

//check
void	ac_check(int ac);
void	fd_check(int fd, char *str);
int		error_msg(char *str);

//child
void	child_program2(t_data data, char **ep);
void	child_program1(t_data data, char **ep);

//free
void	free_data(t_data *data);
void	free_arr_of_arr(char **str);

//forks
void	init_forks(t_data *data, char **ep);

//init malloc
void	malloc_data(t_data *data, char **av, char **ep);

#endif
