/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:56:47 by joferrei          #+#    #+#             */
/*   Updated: 2025/08/27 10:56:48 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	number_of_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*copy_string(const char *start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **matrix, int i)
{
	while (i--)
		free(matrix[i]);
	free(matrix);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	int			i;
	const char	*start;

	i = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc((number_of_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i] = copy_string(start, s - start);
			if (!result[i++])
				return (free_all(result, i - 1), NULL);
		}
		else
			s++;
	}
	return (result[i] = NULL, result);
}
