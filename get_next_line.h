/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:07:36 by bmarecha          #+#    #+#             */
/*   Updated: 2019/12/13 16:32:23 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_strrchr(char *str, char c);
char	*ft_stradd(char *dest, const char *src);
char	*ft_resetto(char *str, char c);
char	*ft_cpyto(char *src, char c);

#endif
