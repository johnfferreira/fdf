/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:49:31 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/11 10:49:33 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

static int	verify(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && verify(*str))
	{
		if (num > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
