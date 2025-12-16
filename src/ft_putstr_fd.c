/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:57:40 by joferrei          #+#    #+#             */
/*   Updated: 2025/06/23 10:57:41 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	len;

	if (!s || fd < 0)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
