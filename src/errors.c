/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:19:40 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/11 11:57:43 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		errout(char *reason, char *arg);

int	errout(char *reason, char *arg)
{
	printf("%s %s\n", reason, arg);
	return (1);
}
