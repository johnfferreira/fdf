/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:13:52 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/14 12:13:53 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	btn_zoom(int key, t_fdf *fdf)
{
	float	step;

	step = 1.0f;
	if (key == 65451)
		fdf->zoom += step;
	else if (key == 65453)
		fdf->zoom -= step;
	if (fdf->zoom < 0.1f)
		fdf->zoom = 0.1f;
}

static void	btn_move(int key, t_fdf *fdf)
{
	float	step;

	step = 10.0f;
	if (key == 97)
		fdf->shift_x -= step;
	else if (key == 100)
		fdf->shift_x += step;
	else if (key == 119)
		fdf->shift_y -= step;
	else if (key == 115)
		fdf->shift_y += step;
}

static void	btn_relevo(int key, t_fdf *fdf)
{
	if (key == 65431)
		fdf->z_scale += 0.1f;
	else if (key == 65433)
		fdf->z_scale -= 0.1f;
	if (fdf->z_scale < 0.01f)
		fdf->z_scale = 0.01f;
}

int	ft_on_key(int key, t_fdf *param)
{
	if (!param)
		return (0);
	if (key == ESC)
	{
		ft_on_close(param);
		return (0);
	}
	btn_relevo(key, param);
	btn_zoom(key, param);
	btn_move(key, param);
	btn_remove_isometric(key, param);
	rotation(key, param);
	if (key == 32)
		param->can_rotate = !param->can_rotate;
	return (0);
}

int	ft_on_close(t_fdf *param)
{
	if (!param)
		return (0);
	free_matrix((int **)param->map, param->height);
	mlx_destroy_image(param->data.mlx, param->data.img);
	mlx_destroy_window(param->data.mlx, param->data.win);
	mlx_destroy_display(param->data.mlx);
	free(param->data.mlx);
	exit(0);
	return (0);
}
