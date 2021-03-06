/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:20:15 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/13 15:51:25 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
	{
		printf("Invalid argument number: 4 needed but used %d\n", (argc - 1));
		exit(0);
	}
	chk_args(argv, &data, envp);
	pipex(&data);
	if (data.path1 != *(data.cmd1))
		free(data.path1);
	if (data.path2 != *(data.cmd2))
		free(data.path2);
	free_matrix(data.cmd1);
	free_matrix(data.cmd2);
	free_matrix(data.fenv);
}
