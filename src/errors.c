/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:19:40 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/12 15:37:09 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		err_ret(char *reason, char *arg);
void	err_log(int type);

int	err_ret(char *reason, char *arg)
{
	printf("%s %s\n", reason, arg);
	return (1);
}

void	err_log(int type)
{
	printf("Error when ");
	if (type == 0)
		perror("doing fork: ");
	else if (type == 1)
		perror("duplicating fds: ");
	else if (type == 2)
		perror("doing pipe: ");
	exit(0);
}
