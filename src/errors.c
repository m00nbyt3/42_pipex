/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:19:40 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/18 14:05:53 by ycarro           ###   ########.fr       */
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
	if (type == 0)
		perror("Error when doing fork: ");
	else if (type == 1)
		perror("Error when duplicating fds: ");
	else if (type == 2)
		perror("Error when doing pipe: ");
	else if (type == 3)
		printf("Error, PATH variable not found\n");
	exit(1);
}
