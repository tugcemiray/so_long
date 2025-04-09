/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:01:28 by tukaraca          #+#    #+#             */
/*   Updated: 2024/11/14 19:52:07 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int n, int sign)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	if (sign < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	ln;
	int		sign;
	int		lenstr;

	ln = n;
	sign = 1;
	if (ln < 0)
		sign = -1;
	ln = sign * ln;
	lenstr = ft_length(ln, sign);
	str = (char *)malloc((lenstr + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[lenstr] = '\0';
	while (--lenstr >= 0)
	{
		str[lenstr] = (ln % 10) + '0';
		ln = ln / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
