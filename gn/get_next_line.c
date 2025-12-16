/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:51:09 by joferrei          #+#    #+#             */
/*   Updated: 2025/07/07 09:51:09 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*delete_line_from_storage_exception(char *storage)
{
	char	*new_storage;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (storage[i] && storage[i] != '\n')
		++i;
	if (!storage[i])
		return (free(storage), NULL);
	i++;
	new_storage = malloc(ft_strlen1(storage) - i + 1);
	if (!new_storage)
		return (free(storage), NULL);
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	return (free(storage), new_storage);
}

static char	*extract_line_before(char *storage)
{
	size_t	i;

	i = 0;
	if (!storage || storage[0] == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	return (ft_substr1(storage, 0, i));
}

static char	*read_from_file_and_save_in_storage(int fd, char *storage)
{
	ssize_t	num_byte;
	char	*tmp;
	char	*new_join;

	if (!storage)
		storage = ft_strdup1("");
	num_byte = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(storage), NULL);
	while (!ft_strchr1(storage, '\n') && num_byte > 0)
	{
		num_byte = read(fd, tmp, BUFFER_SIZE);
		if (num_byte == -1)
			return (free(storage), free(tmp), NULL);
		tmp[num_byte] = '\0';
		new_join = ft_strjoin1(storage, tmp);
		if (!new_join)
			return (free(storage), free(tmp), NULL);
		free(storage);
		storage = new_join;
	}
	free(tmp);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (storage)
			free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = read_from_file_and_save_in_storage(fd, storage);
	if (!storage)
		return (NULL);
	new_line = extract_line_before(storage);
	storage = delete_line_from_storage_exception(storage);
	return (new_line);
}
