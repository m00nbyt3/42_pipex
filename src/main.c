/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:20:15 by ycarro            #+#    #+#             */
/*   Updated: 2021/12/21 15:58:01 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int ret = 0;
	char **command;

	if (argc != 5)
		exit(0);
	argv[2]++;
	chk_files(argv);

	command = malloc(2);
	*command = strdup(argv[2]);
	*(command + 1) = 0;
	ret = execve("/bin/ls", command, envp);
	printf("\nStatus: %d\n", ret);
}