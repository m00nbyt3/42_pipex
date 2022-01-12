/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:19:40 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/12 12:37:18 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		errout(char *reason, char *arg);
void	childerr(int type);

int	errout(char *reason, char *arg)
{
	printf("%s %s\n", reason, arg);
	return (1);
}

void	childerr(int type)
{
	printf("Error when ");
	if (!type)
		perror("doing fork: ");
	else
		perror("duplicating fds: ");
	exit(0);
}
