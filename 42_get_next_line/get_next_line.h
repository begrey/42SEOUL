/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:48:54 by jimkwon           #+#    #+#             */
/*   Updated: 2020/10/26 18:39:04 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

int			get_next_line(int fd, char **line);
char		*is_in_newline(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strdup(char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			split_new_line(char **line, char **prev, char *index);
int			return_status(char **line, char **prev, char *index);

#endif
