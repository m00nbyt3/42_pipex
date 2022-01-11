/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:20:15 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/11 11:33:42 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	char	*touse;
	char	**cmd;
	char	**fenv;

	if (argc != 5)
		exit(0);
	chk_files(argv);
	cmd = ft_split(argv[2], ' ');
	if (access(*cmd, X_OK))
	{
		fenv = ft_split(envp[format_path(envp)] + 5, ':');
		touse = srch_path(cmd[0], fenv);
	}
	else
		touse = *cmd;
	//pipex(open(argv[1], argv[4], ))
	ret = 0;
	ret = execve(touse, cmd, envp);
	/*free(touse);
	free(cmd);*/
	printf("\nStatus: %d\n", ret);
}