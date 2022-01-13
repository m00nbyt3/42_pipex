/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:41:29 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/13 15:44:54 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	chk_args(char **argv, t_data *data, char **envp);
void	chk_files(char *file1);
void	chk_cmds(t_data *data, char **envp);

void	chk_args(char **argv, t_data *data, char **envp)
{
	data->file1 = argv[1];
	data->file2 = argv[4];
	chk_files(data->file1);
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	chk_cmds(data, envp);
}

void	chk_files(char *file1)
{
	int	err;

	err = 0;
	if (access(file1, R_OK | X_OK))
		err = err_ret("Invalid file:", file1);
	if (err)
		exit(0);
}

void	chk_cmds(t_data *data, char **envp)
{
	if (*envp)
		data->fenv = ft_split(envp[format_path(envp)] + 5, ':');
	else
	{
		data->fenv = malloc(1 *sizeof(int));
		*data->fenv = 0;
	}
	if (access(*(data->cmd1), X_OK))
		data->path1 = srch_path(*(data->cmd1), data->fenv);
	else
		data->path1 = *(data->cmd1);
	if (!data->path1)
		err_ret("Invalid command: ", *(data->cmd1));
	if (access(*(data->cmd2), X_OK))
		data->path2 = srch_path(*(data->cmd2), data->fenv);
	else
		data->path2 = *(data->cmd2);
	if (!data->path2)
		err_ret("Invalid command: ", *(data->cmd2));
	if (!data->path1 || !data->path2)
		exit(0);
}
