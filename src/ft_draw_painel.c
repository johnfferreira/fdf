/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_painel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:13:35 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/14 12:13:38 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	aux_isometric(t_point *a, t_point *b, t_fdf *fdf)
{
	rotate_point(a, fdf);
	rotate_point(b, fdf);
	if (!fdf->projection)
	{
		ft_isometric(&a->x, &a->y, a->z);
		ft_isometric(&b->x, &b->y, b->z);
	}
}

static void	draw_line(t_fdf *fdf, t_point a, t_point b)
{
	float	x_step;
	float	y_step;
	float	max;
	int		steps;

	aux_isometric(&a, &b, fdf);
	a.x = a.x * fdf->zoom + fdf->shift_x;
	a.y = a.y * fdf->zoom + fdf->shift_y;
	b.x = b.x * fdf->zoom + fdf->shift_x;
	b.y = b.y * fdf->zoom + fdf->shift_y;
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = fmax(fabs(x_step), fabs(y_step));
	if (max == 0)
		return ;
	x_step /= max;
	y_step /= max;
	steps = (int)max;
	while (steps-- >= 0)
	{
		my_mlx_pixel_put(&fdf->data, (int)a.x, (int)a.y, a.color);
		a.x += x_step;
		a.y += y_step;
	}
}

static t_point	create_point(t_fdf *fdf, int x, int y, t_center *center)
{
	t_point	p;

	p.x = (x - center->x);
	p.y = (y - center->y);
	p.z = fdf->map[y][x].z * fdf->z_scale;
	p.color = fdf->map[y][x].color;
	return (p);
}

static void	draw_connections(t_fdf *fdf, t_point a, int x, int y)
{
	t_point		b;
	t_center	center;

	center.x = (float)fdf->width / 2.0;
	center.y = (float)fdf->height / 2.0;
	if (x < fdf->width - 1)
	{
		b = create_point(fdf, x + 1, y, &center);
		draw_line(fdf, a, b);
	}
	if (y < fdf->height - 1)
	{
		b = create_point(fdf, x, y + 1, &center);
		draw_line(fdf, a, b);
	}
}

void	draw_map(t_fdf *fdf)
{
	int			x;
	int			y;
	t_point		a;
	t_center	center;

	center.x = (float)fdf->width / 2.0;
	center.y = (float)fdf->height / 2.0;
	y = -1;
	while (++y < fdf->height)
	{
		x = -1;
		while (++x < fdf->width)
		{
			a = create_point(fdf, x, y, &center);
			draw_connections(fdf, a, x, y);
		}
	}
}
