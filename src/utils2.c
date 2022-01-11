/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:26:45 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/10 11:32:16 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split(char const *s, char c);
size_t	wrd_count(char const *str, char c);
size_t	wrd_size (char const *s, char c, size_t *i);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c)
{
	char	**table;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	table = (char **)malloc((wrd_count(s, c) + 1) * sizeof(char *));
	if (!table)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			size = wrd_size(s, c, &i);
			table[j] = ft_substr(s, (unsigned int)(i - size), size);
			j++;
		}
	}
	table[j] = 0;
	return (table);
}

size_t	wrd_count(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			i++;
			while (*str != c && *str)
				str++;
		}
	}
	return (i);
}

size_t	wrd_size (char const *s, char c, size_t *i)
{
	size_t	size;

	size = 0;
	while (s[*i] != c && s[*i])
	{
		size++;
		*i += 1;
	}
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			size;
	int				i;
	unsigned int	tam;

	if (!s)
		return (0);
	if (start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	size = (len + 1) * sizeof(char);
	str = (char *)malloc(size);
	if (!str)
		return (0);
	tam = (unsigned int)ft_strlen(s);
	if (start < tam)
	{
		i = 0;
		while (len--)
			str[i++] = s[start++];
		str[i] = '\0';
	}
	return (str);
}
