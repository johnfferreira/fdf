/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:49:12 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/11 10:49:13 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../gn/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// SIZE
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

// COLOR
# define GREEN 0xB0CE88
# define WHITE 0xFFFFFF

// event key
# define ON_DESTROY 17
# define ESC 65307

// Angle in radian
# define RADIAN_ANGLE 0.523598776 // 30 GRAU

// STRUCT
typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_center
{
	float	x;
	float	y;
}			t_center;

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;
}			t_point;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_point	**map;
	t_data	data;
	int		shift_x;
	int		shift_y;
	float	zoom;
	float	z_scale;
	int		projection;
	int		can_rotate;
	float	angle_z;
}			t_fdf;

typedef struct s_pmap
{
	t_point	**z_matriz;
	char	*line;
	char	**v_split;
}			t_pmap;

typedef struct s_aux
{
	char	*line;
	int		wd_equal;
}			t_aux;

void		ft_exit(char *s);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_point		**parse_map(char *str, int *width, int *height);
void		ft_isometric(float *x, float *y, int z);
// libft
char		**ft_split(char const *s, char c);
long		ft_atol(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_putstr_fd(char *s, int fd);
//
void		draw_map(t_fdf *fdf);
void		free_matrix(int **z_matrix, int h);
// event
int			ft_on_key(int key, t_fdf *param);
int			ft_on_close(t_fdf *param);
void		btn_remove_isometric(int key, t_fdf *param);
int			mouse_hook(int key, int x, int y, t_fdf *fdf);
void		rotation(int key, t_fdf *fdf);
void		rotate_point(t_point *p, t_fdf *fdf);
// util main
void		set_auto_zoom(t_fdf *fdf);
int			render_next_frame(t_fdf *fdf);

// map height
int			get_map_height(char *map_name, int *width);
void		ft_free_split(char **split);
#endif
