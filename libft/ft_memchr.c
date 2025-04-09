/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:57:19 by tukaraca          #+#    #+#             */
/*   Updated: 2024/11/12 18:52:24 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		uc;

	str = ptr;
	uc = (unsigned char)c;
	while (n != 0)
	{
		n--;
		if (*str == uc)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
