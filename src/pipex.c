/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:28:15 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/11 13:53:53 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_data *data);

void	pipex(t_data *data)
{
	t_fd	fd;
	int		*bypass;
	int		status;
	pid_t	child1;
	pid_t	child2;

	bypass = malloc(2 *sizeof(int));
	pipe(bypass);
	fd.infile = open(fname1, O_RDONLY);
	fd.outfile = open(fname2, O_RDWR, O_CREAT, O_TRUNC, 0666);
	child1 = fork();
	if (child1 == -1)
		childerr();
	else if(!child1)
		first_ch(fd.infile, data->command1, bypass);
	child2 = fork();
	if (child2 == -1)
		childerr();
	else if(!child2)
		second_ch(fd.outfile, data->command2, bypass);
	close(bypass[0]);
	close(bypass[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	first_ch(fd.infile, data->command1, bypass)
{
	
}

/*void	get_fds(char *fname1, char *fname2, t_fd *fd)
{
	fd->infile = open(fname1, O_RDONLY);
	fd->outfile = open(fname2, O_RDWR, O_CREAT, O_TRUNC, 0666);
}*/