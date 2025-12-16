/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:50:04 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/11 10:50:07 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	parse_point(char *str)
{
	t_point	point;
	char	**parts;

	parts = ft_split(str, ',');
	point.z = (int)ft_atol(parts[0]);
	if (parts[1])
		point.color = (int)strtol(parts[1], NULL, 16);
	else
		point.color = GREEN;
	ft_free_split(parts);
	return (point);
}

static void	free_matriz(int **matrix, int y)
{
	while (--y >= 0)
		free(matrix[y]);
	free(matrix);
}

static void	put_in_row_matriz(t_pmap *pmp, int y, int width)
{
	int	x;

	pmp->v_split = ft_split(pmp->line, ' ');
	x = -1;
	while (++x < width)
		pmp->z_matriz[y][x] = parse_point(pmp->v_split[x]);
	ft_free_split(pmp->v_split);
}

t_point	**parse_map(char *map_name, int *width, int *height)
{
	t_pmap	pmp;
	int		fd;
	int		y;

	*height = get_map_height(map_name, width);
	pmp.z_matriz = malloc(*height * sizeof(t_point *));
	if (!pmp.z_matriz)
		ft_exit("Erro ao alocar a matriz");
	fd = open(map_name, O_RDONLY);
	y = 0;
	pmp.line = get_next_line(fd);
	while (pmp.line)
	{
		pmp.z_matriz[y] = malloc(*width * sizeof(t_point));
		if (!pmp.z_matriz[y])
			return (free_matriz((int **)pmp.z_matriz, y), exit(1),
				NULL);
		put_in_row_matriz(&pmp, y++, *width);
		free(pmp.line);
		pmp.line = get_next_line(fd);
	}
	close(fd);
	return (pmp.z_matriz);
}
