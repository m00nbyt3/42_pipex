/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:21:21 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/10 15:37:14 by ycarro           ###   ########.fr       */
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
int		format_path(char **envp);
char	*srch_path(char *cmd, char **fenv);
char	*set_path(char *fenv, char *cmd);


//Utils
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		setc(char const *org, char const *dst);
char	**ft_split(char const *s, char c);
size_t	wrd_count(char const *str, char c);
size_t	wrd_size (char const *s, char c, size_t *i);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//Errors
int		errout(char *reason, char *arg);
void	chk_files(char **files);

#endif