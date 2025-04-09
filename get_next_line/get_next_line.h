/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:21:36 by tukaraca          #+#    #+#             */
/*   Updated: 2024/12/24 21:00:38 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcpy(char *dst, char *src, int size);
char	*get_line_first(char *str);
char	*get_read(int fd, char *str);
char	*get_last_line(char *str);
char	*get_next_line(int fd);

#endif
