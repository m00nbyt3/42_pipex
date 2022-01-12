/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:21:21 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/12 15:36:58 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Header files
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

//Structs
typedef struct s_data
{
	char	*file1;
	char	*file2;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	char	**fenv;
		
}			t_data;

typedef struct s_fd
{
	int	infile;
	int	outfile;	
}			t_fd;

//Functions
int		format_path(char **envp);
char	*srch_path(char *cmd, char **fenv);
char	*set_path(char *fenv, char *cmd);
void	pipex(t_data *data);
void	child_pr(int infile, int outfile, t_data *data, int lap);

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
void	chk_args(char **argv, t_data *data, char **envp);
void	chk_files(char *file1, char *file2);
void	chk_cmds(t_data *data, char **envp);

//Errors
int		err_ret(char *reason, char *arg);
void	err_log(int type);

#endif