/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:41:53 by ycarro            #+#    #+#             */
/*   Updated: 2022/01/10 15:27:44 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		setc(char const *org, char const *dst);

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		tam;

	tam = ft_strlen(s1) + 1;
	str = malloc(tam);
	if (!str)
		return (0);
	return (ft_memcpy(str, s1, tam));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	unsigned char		*str2;

	if (!(src || dst))
		return (0);
	str1 = (const unsigned char *)src;
	str2 = (unsigned char *)dst;
	i = -1;
	while (++i < n)
		str2[i] = str1[i];
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;
	char	*aux;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (0);
	aux = str;
	while (*s1 || *s2)
	{
		if (*s1)
			s1 += setc(s1, aux);
		else if (*s2)
			s2 += setc(s2, aux);
		aux++;
	}
	*aux = '\0';
	return (str);
}

int	setc(char const *org, char const *dst)
{
	char	*mod;

	mod = (char *)dst;
	*mod = *org;
	return (1);
}
