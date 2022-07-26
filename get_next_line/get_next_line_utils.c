/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:17:09 by mbouthai          #+#    #+#             */
/*   Updated: 2022/07/26 14:17:37 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substrs(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start > str_len)
		start = str_len;
	if (len > str_len - start)
		len = str_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str + start, len + 1);
	if (!*result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*ft_strjoins(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	if (s1)
		ft_strlcpy(result, s1, s1_len + 1);
	else
		result[0] = '\0';
	if (s2)
		ft_strlcat(result, s2, s1_len + s2_len + 1);
	if (!*result)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	free(s1);
	return (result);
}
