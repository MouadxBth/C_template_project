/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:17:54 by mbouthai          #+#    #+#             */
/*   Updated: 2022/07/26 14:40:19 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find(char c, char *str)
{
	int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (!c && !str[index])
		return (index);
	return (-1);
}

char	*ft_fill_stash(int fd, char *stash, int *new_line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoins(stash, buffer);
		*new_line = ft_find('\n', stash);
		if (*new_line >= 0)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_extract_line(char *stash, int new_line)
{
	char	*line;
	char	*temp;

	if (!stash)
		return (NULL);
	if (new_line >= 0)
	{
		temp = ft_substrs(stash, 0, new_line + 1);
		line = ft_strjoins(NULL, temp);
		free(temp);
	}
	else
		line = ft_strjoins(NULL, stash);
	return (line);
}

char	*ft_process_stash(char *stash, int new_line)
{
	char	*temp;

	if (!stash)
		return (NULL);
	if (new_line < 0)
	{
		free(stash);
		return (NULL);
	}
	temp = ft_substrs(stash, new_line + 1, ft_strlen(stash));
	free(stash);
	stash = temp;
	return (stash);
}	

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD + 1];
	char		*line;
	int			new_line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_fill_stash(fd, stash[fd], &new_line);
	if (!stash[fd])
		return (NULL);
	if (!*stash[fd])
	{
		free(stash[fd]);
		return (NULL);
	}
	line = ft_extract_line(stash[fd], new_line);
	stash[fd] = ft_process_stash(stash[fd], new_line);
	return (line);
}
