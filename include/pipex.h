/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:21:21 by ycarro            #+#    #+#             */
/*   Updated: 2021/12/21 15:46:33 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Header files
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>

//Functions



//Errors
int		errout(char *reason, char *arg);
void	chk_files(char **files);

#endif