/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:16:13 by mbouthai          #+#    #+#             */
/*   Updated: 2022/07/26 15:24:58 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# ifndef MAX_FD
#  define MAX_FD 128
# endif

char	*ft_substrs(char const *str, unsigned int start, size_t len);
char	*ft_strjoins(char *s1, char *s2);

int		ft_find(char c, char *str);
char	*ft_fill_stash(int fd, char *stash, int *new_line);
char	*ft_extract_line(char *stash, int new_line);
char	*ft_process_stash(char *stash, int new_line);

char	*get_next_line(int fd);

#endif
