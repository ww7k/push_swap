/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:34:04 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 05:09:08 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*n;

	if (!s)
		return (0);
	if (s[0] == '\0' || ft_strlen(s) <= start)
		return (ft_strdup(""));
	i = 0;
	while (s[start + i])
		i++;
	if (len > i)
		len = i;
	n = malloc(sizeof(char) * (len +1));
	if (!n)
		return (NULL);
	i = 0;
	while (start < ft_strlen((char *)s) && s[start + i] != '\0' && i < len)
	{
		n[i] = s[start + i];
		i++;
	}
	n[i] = '\0';
	return (n);
}

static size_t	counter(char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (cnt);
}

static int	ft_wordlen(char *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!str[i])
				return (ft_freestr(str));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	str[i] = NULL;
	return (str);
}
