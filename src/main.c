/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:20:15 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/11 12:44:55 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		ret;

	if (argc != 5)
		exit(0);
	chk_args(argv, &data, envp);
	//pipex();
	ret = 0;
	ret = execve(data.path2, data.cmd2, envp);
	/*free(touse);
	free(cmd);*/
	printf("\nStatus: %d\n", ret);
}