/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:48:18 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/11 10:48:26 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	arg_exception(void)
{
	ft_putstr_fd("Use: ./fdf <map.fdf>\n", 2);
	exit(1);
}

static int	init_mlx(t_fdf *fdf)
{
	fdf->data.mlx = mlx_init();
	if (!fdf->data.mlx)
	{
		free_matrix((int **)fdf->map, fdf->height);
		ft_putstr_fd("Erro no servidor do minilibix", 2);
		return (1);
	}
	fdf->data.win = mlx_new_window(fdf->data.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!fdf->data.win)
		return (free(fdf->data.mlx),
			free_matrix((int **)fdf->map, fdf->height), 1);
	fdf->data.img = mlx_new_image(fdf->data.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fdf->data.img)
		return (free(fdf->data.win), free(fdf->data.mlx),
			free_matrix((int **)fdf->map, fdf->height), 1);
	fdf->data.addr = mlx_get_data_addr(fdf->data.img,
			&fdf->data.bits_per_pixel,
			&fdf->data.line_length, &fdf->data.endian);
	if (!fdf->data.addr)
		return (free(fdf->data.win), free(fdf->data.mlx),
			free(fdf->data.img),
			free_matrix((int **)fdf->map, fdf->height), 1);
	return (0);
}

static void	init_fdf(t_fdf *fdf, char *map_name)
{
	ft_bzero(fdf, sizeof(*fdf));
	fdf->map = parse_map(map_name, &fdf->width, &fdf->height);
	fdf->z_scale = 1.0f;
	fdf->projection = 0;
	fdf->angle_z = 0.0f;
	set_auto_zoom(fdf);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		arg_exception();
	init_fdf(&fdf, av[1]);
	if (init_mlx(&fdf))
		return (1);
	mlx_hook(fdf.data.win, ON_DESTROY, 0, ft_on_close, &fdf);
	mlx_key_hook(fdf.data.win, ft_on_key, &fdf);
	mlx_mouse_hook(fdf.data.win, mouse_hook, &fdf);
	mlx_loop_hook(fdf.data.mlx, render_next_frame, &fdf);
	mlx_loop(fdf.data.mlx);
	return (0);
}
