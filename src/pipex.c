/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:28:15 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/12 13:46:17 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_data *data);
void	child_pr(int infile, int outfile, t_data *data, int lap);

void	pipex(t_data *data)
{
	t_fd	fd;
	int		bypass[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(bypass); //Debug
	fd.infile = open(data->file1, O_RDONLY);
	fd.outfile = open(data->file2, O_RDWR, O_CREAT, O_TRUNC, 0666);
	child1 = fork();
	if (child1 == -1)
		childerr(1);
	else if(!child1)
		child_pr(fd.infile, bypass[1], data, 0);
	child2 = fork();
	if (child2 == -1)
		childerr(0);
	else if(!child2)
		child_pr(bypass[0], fd.outfile, data, 1);
	close(bypass[0]);
	close(bypass[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	child_pr(int infile, int outfile, t_data *data, int lap)
{
	if (!lap)
		close(outfile - 1);
	else
		close(infile + 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		childerr(1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		childerr(1);
	if (!lap)
	{
		close(infile);
		execve(data->path1, data->cmd1, data->fenv);
	}
	else
	{
		close(outfile);
		execve(data->path2, data->cmd2, data->fenv);
	}
}

/*void	get_fds(char *fname1, char *fname2, t_fd *fd)
{
	fd->infile = open(fname1, O_RDONLY);
	fd->outfile = open(fname2, O_RDWR, O_CREAT, O_TRUNC, 0666);
}*/