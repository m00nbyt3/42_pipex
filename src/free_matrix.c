/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:03:29 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/13 15:03:58 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_matrix(char **matrix);

void	free_matrix(char **matrix)
{
	char **tmp;

	tmp = matrix;
	while(*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(matrix);
}