/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:30:06 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/09 21:42:53 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ftt_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ftt_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	return (0);
}

char	*ftt_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	ret = malloc(sizeof(char) * (ftt_strlen(s1) + ftt_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	while (s1[a])
	{
		ret[a] = s1[a];
		a ++;
	}
	while (s2[b])
	{
		ret[a + b] = s2[b];
		b ++;
	}
	ret[a + b] = '\0';
	return (free(s1), ret);
}
