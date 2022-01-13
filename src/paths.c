/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:16:22 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/13 13:00:41 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		format_path(char **envp);
char	*srch_path(char *cmd, char **fenv);
char	*set_path(char *fenv, char *cmd);

int	format_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (*(envp[i]) == 'P' && *(envp[i] + 1) == 'A' && *(envp[i] + 2) == 'T' \
			&& *(envp[i] + 3) == 'H' && *(envp[i] + 4) == '=')
			return (i);
	return (-1);
}

char	*srch_path(char *cmd, char **fenv)
{
	char	*tmp;

	while (*fenv)
	{
		cmd = cmd + 0;
		tmp = set_path(*fenv, cmd);
		if (!(access(tmp, X_OK)))
			return (tmp);
		fenv++;
		free(tmp);
	}
	return (0);
}

char	*set_path(char *fenv, char *cmd)
{
	char	*addbar;
	char	*def;

	addbar = ft_strjoin(fenv, "/");
	def = ft_strjoin(addbar, cmd);
	free(addbar);
	return (def);
}
