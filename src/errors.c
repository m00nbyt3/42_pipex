/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:19:40 by ycarro            #+#    #+#             */
/*   Updated: 2021/12/21 13:08:20 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		errout(char *reason, char *arg);
void	chk_files(char **files);

int	errout(char *reason, char *arg)
{
	printf("%s %s\n", reason, arg);
	return (1);
}

void	chk_files(char **files)
{
	int err;

	err = 0;
	if (access(files[1], R_OK | X_OK))
		err = errout("Invalid file:", files[1]);
	if (access(files[4], R_OK | X_OK))
		err = errout("Invalid file:", files[4]);
	if (err)
		exit(0);
}