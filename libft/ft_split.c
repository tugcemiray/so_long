/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:24:09 by tukaraca          #+#    #+#             */
/*   Updated: 2024/11/14 19:56:12 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	wordcount;
	int	inword;

	wordcount = 0;
	inword = 0;
	while (*s)
	{
		if (*s == c)
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			wordcount++;
		}
		s++;
	}
	return (wordcount);
}

static char	*ft_getword(const char *s, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len + 1) * (sizeof(char)));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **result, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	**ft_fill(char **result, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[j] = ft_getword(&s[start], i - start);
			if (result[j] == NULL)
			{
				ft_free_split(result, j);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_wordcount(s, c);
	result = malloc((count + 1) * (sizeof(char *)));
	if (result == NULL)
		return (NULL);
	if (ft_fill(result, s, c) == NULL)
		return (NULL);
	result[count] = NULL;
	return (result);
}
