/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:14:26 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/14 16:14:27 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(int **z_matrix, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(z_matrix[i]);
		++i;
	}
	free(z_matrix);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_fdf *fdf)
{
	if (!fdf || !fdf->data.mlx || !fdf->data.win)
		return (0);
	mlx_destroy_image(fdf->data.mlx, fdf->data.img);
	fdf->data.img = mlx_new_image(fdf->data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->data.addr = mlx_get_data_addr(fdf->data.img, &fdf->data.bits_per_pixel,
			&fdf->data.line_length, &fdf->data.endian);
	mlx_clear_window(fdf->data.mlx, fdf->data.win);
	if (fdf->can_rotate)
		fdf->angle_z += 0.01f;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->data.mlx, fdf->data.win, fdf->data.img, 0, 0);
	return (0);
}

void	set_auto_zoom(t_fdf *fdf)
{
	float	max_dim;

	if (fdf->width > fdf->height)
		max_dim = fdf->width;
	else
		max_dim = fdf->height;
	if (max_dim > 500)
		fdf->zoom = 400.0f / max_dim;
	else if (max_dim > 200)
		fdf->zoom = 500.0f / max_dim;
	else if (max_dim > 100)
		fdf->zoom = 300.0f / max_dim;
	else if (max_dim > 50)
		fdf->zoom = 200.0f / max_dim;
	else
		fdf->zoom = 70.0f / max_dim;
	if (fdf->zoom > 20.0f)
		fdf->zoom = 20.0f;
	if (fdf->zoom < 0.5f)
		fdf->zoom = 0.5f;
	fdf->shift_x = WINDOW_WIDTH / 2;
	fdf->shift_y = WINDOW_HEIGHT / 2;
}
