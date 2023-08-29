/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:59:32 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/26 16:03:06 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	size_t	str_size;
	char	*new_str;

	str_size = ft_strlen(s) + 1;
	new_str = (char *)malloc(str_size * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, str_size);
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index1;
	size_t	index2;
	char	*new_str;

	if (s1 == NULL)
		s1 = ft_strdup("");
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	index1 = 0;
	while (s1[index1])
	{
		new_str[index1] = s1[index1];
		index1++;
	}
	index2 = 0;
	while (s2[index2])
	{
		new_str[index1 + index2] = s2[index2];
		index2++;
	}
	free((char *)s1);
	new_str[index1 + index2] = '\0';
	return (new_str);
}
