/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:02:22 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/13 10:02:26 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z)
{
	float	xp;
	float	yp;

	xp = *x;
	yp = *y;
	*x = (xp - yp) * cos(RADIAN_ANGLE);
	*y = (xp + yp) * sin(RADIAN_ANGLE) - (float)z * 0.5f;
}

void	btn_remove_isometric(int key, t_fdf *param)
{
	if (key == 65289)
		param->projection = !param->projection;
}

void	rotate_point(t_point *p, t_fdf *fdf)
{
	float	prev_x;
	float	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = prev_x * cos(fdf->angle_z) - prev_y * sin(fdf->angle_z);
	p->y = prev_x * sin(fdf->angle_z) + prev_y * cos(fdf->angle_z);
}
