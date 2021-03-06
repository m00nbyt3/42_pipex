/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:41:29 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/18 13:36:34 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	chk_args(char **argv, t_data *data, char **envp);
int		chk_files(t_data *data);
int		chk_cmds(t_data *data, char **envp);

void	chk_args(char **argv, t_data *data, char **envp)
{
	int	err;

	err = 0;
	data->err[0] = 0;
	data->err[1] = 0;
	data->file1 = argv[1];
	data->file2 = argv[4];
	err += chk_files(data);
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	err += chk_cmds(data, envp);
	if (err)
		exit(1);
}

int	chk_files(t_data *data)
{
	if (access(data->file1, R_OK))
		data->err[0] = err_ret("Invalid file:", data->file1);
	if (!access(data->file2, F_OK))
		if (access(data->file2, W_OK))
			data->err[1] = err_ret("Could not write on file:", data->file1);
	if (data->err[0] && data->err[1])
		return (1);
	else
		return (0);
}

int	chk_cmds(t_data *data, char **envp)
{
	if (*envp)
		data->fenv = ft_split(envp[format_path(envp)] + 5, ':');
	else
	{
		data->fenv = malloc(1 * sizeof(int));
		*data->fenv = 0;
	}
	if (access(*(data->cmd1), X_OK))
		data->path1 = srch_path(*(data->cmd1), data->fenv);
	else
		data->path1 = *(data->cmd1);
	if (!data->path1)
		data->err[0] = err_ret("Invalid command: ", *(data->cmd1));
	if (access(*(data->cmd2), X_OK))
		data->path2 = srch_path(*(data->cmd2), data->fenv);
	else
		data->path2 = *(data->cmd2);
	if (!data->path2)
		data->err[1] = err_ret("Invalid command: ", *(data->cmd2));
	if (data->err[0] && data->err[1])
		return (1);
	else
		return (0);
}
