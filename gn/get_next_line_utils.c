/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:44:55 by joferrei          #+#    #+#             */
/*   Updated: 2025/07/07 09:44:56 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup1(const char *src)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	dst = malloc((ft_strlen1(src) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr1(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	pc;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	pc = (unsigned char)c;
	while (str[i] != '\0')
	{
		if (str[i] == pc)
			return ((char *)(str + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen1(s);
	if (start >= s_len)
		return (ft_strdup1(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str_join;

	str_join = malloc((ft_strlen1(s1) + ft_strlen1(s2) + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str_join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str_join[i] = s2[j];
		i++;
		j++;
	}
	str_join[i] = '\0';
	return (str_join);
}
