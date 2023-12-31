/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:59:30 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/28 09:47:06 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_file(int fd, char *buffer);
static char	*ft_make_line(char *content);
static char	*ft_update_buffer(char *buffer);

char	*get_next_line(int fd)
{
	static char	*after_new_line_content[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	after_new_line_content[fd] = ft_read_file(fd, after_new_line_content[fd]);
	if (after_new_line_content[fd] == NULL)
		return (NULL);
	line = ft_make_line(after_new_line_content[fd]);
	after_new_line_content[fd] = ft_update_buffer(after_new_line_content[fd]);
	return (line);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*file_content;
	ssize_t	num_bytes;

	file_content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!file_content)
		return (NULL);
	num_bytes = 1;
	while (!ft_strchr(buffer, '\n') && num_bytes)
	{
		num_bytes = read(fd, file_content, BUFFER_SIZE);
		if (num_bytes < 0)
		{
			free(file_content);
			free(buffer);
			return (NULL);
		}
		file_content[num_bytes] = '\0';
		buffer = ft_strjoin(buffer, file_content);
	}
	free(file_content);
	return (buffer);
}

static char	*ft_make_line(char *content)
{
	char	*new_line_position;
	char	*line;
	size_t	line_size;

	if (content[0] == '\0')
		return (NULL);
	new_line_position = ft_strchr(content, '\n');
	if (new_line_position == NULL)
		return (ft_strdup(content));
	else
		line_size = (new_line_position - content) + 1;
	line = malloc((line_size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, content, line_size + 1);
	return (line);
}

static char	*ft_update_buffer(char *buffer)
{
	char	*new_line_position;
	char	*new_buffer;

	new_line_position = ft_strchr(buffer, '\n');
	if (new_line_position == NULL)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(new_line_position + 1);
	free(buffer);
	return (new_buffer);
}
