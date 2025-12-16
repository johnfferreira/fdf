/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:44:33 by joferrei          #+#    #+#             */
/*   Updated: 2025/07/07 09:44:35 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen1(const char *s);
char	*ft_strchr1(const char *s, int c);
char	*ft_substr1(char const *s, unsigned int start, size_t len);
char	*ft_strjoin1(char const *s1, char const *s2);
char	*ft_strdup1(const char *src);

#endif
