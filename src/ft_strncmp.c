/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:27:52 by joferrei          #+#    #+#             */
/*   Updated: 2025/06/18 11:27:53 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	if (!s1 || !s2)
	{
		if (s1 == s2)
			return (0);
		else if (s1)
			return (*s1);
		else
			return (-(*s2));
	}
	i = 0;
	while (i < n && str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
