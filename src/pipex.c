/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:28:15 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/18 13:40:24 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_data *data);
void	child_pr(int infile, int outfile, t_data *data, int lap);

void	pipex(t_data *data)
{
	int		bypass[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(bypass))
		err_log(2);
	data->fd[0] = open(data->file1, O_RDONLY);
	data->fd[1] = open(data->file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	child1 = fork();
	if (child1 == -1)
		err_log(0);
	else if (!child1)
		child_pr(data->fd[0], bypass[1], data, 0);
	child2 = fork();
	if (child2 == -1)
		err_log(0);
	else if (!child2)
		child_pr(bypass[0], data->fd[1], data, 1);
	close(bypass[0]);
	close(bypass[1]);
	close(data->fd[0]);
	close(data->fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	child_pr(int infile, int outfile, t_data *data, int lap)
{
	if (!lap)
	{
		close(outfile - 1);
		close(infile + 1);
	}
	else
	{
		close(infile + 1);
		close(outfile -1);
	}
	if (!data->err[lap])
	{
		if (dup2(infile, 0) == -1)
			err_log(1);
		if (dup2(outfile, 1) == -1)
			err_log(1);
	}
	close(infile);
	close(outfile);
	if (data->err[lap])
		exit(0);
	if (!lap)
		execve(data->path1, data->cmd1, data->fenv);
	else
		execve(data->path2, data->cmd2, data->fenv);
}
