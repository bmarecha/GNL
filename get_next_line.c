/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:51:20 by bmarecha          #+#    #+#             */
/*   Updated: 2019/12/13 16:57:03 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*memory[126];
	char			*temp;
	int				res;
	int				readv;

	if (!line || BUFFER_SIZE <= 0 || fd == -1 ||
			(!(memory[fd]) && !(memory[fd] = malloc(1))) ||
			!(temp = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_strrchr(memory[fd], '\n')
		&& (readv = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[readv] = '\0';
		memory[fd] = ft_stradd(memory[fd], temp);
	}
	if (readv == 0)
		memory[fd] = ft_stradd(memory[fd], temp);
	free(temp);
	res = ft_strrchr(memory[fd], '\n');
	*line = ft_cpyto(memory[fd], '\n');
	memory[fd] = ft_resetto(memory[fd], '\n');
	if (readv == -1)
		return (-1);
	return (res);
}
