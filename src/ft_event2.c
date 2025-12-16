/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:34:27 by joferrei          #+#    #+#             */
/*   Updated: 2025/11/17 10:34:31 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int key, int x, int y, t_fdf *fdf)
{
	float	step;

	step = 1.0f;
	(void)x;
	(void)y;
	if (key == 4)
		fdf->zoom += step;
	else if (key == 5)
	{
		if (fdf->zoom > 1)
			fdf->zoom -= 1;
	}
	return (0);
}

void	rotation(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 113)
		fdf->angle_z -= 0.5;
	if (key == 101)
		fdf->angle_z += 0.5;
}
