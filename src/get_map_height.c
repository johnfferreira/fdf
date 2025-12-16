/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:42:50 by joferrei          #+#    #+#             */
/*   Updated: 2025/10/14 16:42:51 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	*str2;
	unsigned char	pc;
	int				i;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	str2 = NULL;
	pc = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == pc)
			str2 = str + i;
		i++;
	}
	if (pc == '\0')
		return ((char *)(str + i));
	return ((char *)str2);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

static int	count_column(char *str)
{
	int		count;
	char	**s;
	char	*trim;

	if (!str)
		return (0);
	trim = ft_strtrim(str, "\n");
	count = 0;
	s = ft_split(trim, ' ');
	while (s[count])
		++count;
	ft_free_split(s);
	free(trim);
	return (count);
}

static int	is_valid_map_exception(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strrchr(s, '.');
	if (str && *(str - 1) && *(str - 1))
	{
		if (*(str - 1) == '/')
			ft_exit("Mapa invalido: nao do tipo .fdf");
		while (str[i])
			++i;
		if (i == 4)
			if (!ft_strncmp(str, ".fdf", 4))
				return (1);
	}
	ft_exit("Mapa invalido: nao do tipo .fdf");
	return (0);
}

int	get_map_height(char *map_name, int *width)
{
	int		fd;
	int		height;
	t_aux	aux;

	is_valid_map_exception(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_exit("Erro ao ler o ficheiro");
	aux.line = get_next_line(fd);
	if (!aux.line)
		ft_exit("erro: get_next_line no get_map_height");
	*width = count_column(aux.line);
	aux.wd_equal = *width;
	height = 0;
	while (aux.line)
	{
		if (aux.wd_equal != *width)
			return (close(fd), free(aux.line), get_next_line(-1),
				ft_exit("mapa invalido: wd !="), 0);
		height++;
		free(aux.line);
		aux.line = get_next_line(fd);
		aux.wd_equal = count_column(aux.line);
	}
	return (get_next_line(-1), close(fd), height);
}
