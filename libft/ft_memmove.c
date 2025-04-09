/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:12:40 by tukaraca          #+#    #+#             */
/*   Updated: 2024/10/24 20:52:47 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (! dst && ! src)
		return (NULL);
	else if (dst < src)
		return (ft_memcpy(dst, src, len));
	else if (dst > src)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	return (d);
}
