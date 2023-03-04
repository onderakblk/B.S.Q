/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:24:23 by oakbulak          #+#    #+#             */
/*   Updated: 2023/02/24 01:31:29 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/reader.h"

int	read_line(int fd)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
	while (c != '\n')
	{
		read(fd, &c, 1);
		i++;
	}
	return (i);
}

t_info	*map_info(t_info *info, char *frst_line)
{
	int	i;
	int	line_nbr;

	i = 0;
	line_nbr = 0;
	while (frst_line[i] >= '0' && frst_line[i] <= '9')
	{
		line_nbr *= 10;
		line_nbr += frst_line[i] - '0';
		i++;
	}
	info->satir_sayisi = line_nbr;
	info->bosluk = frst_line[i];
	info->engel = frst_line[i + 1];
	info->full = frst_line[i + 2];
	return (info);
}

char	**create_map(int line_nbr, int char_nbr, int filedes)
{
	char	**map_table;
	int		i;

	i = 0;
	map_table = (char **) malloc(sizeof(char *) * line_nbr);
	while (i < line_nbr)
	{
		map_table[i] = (char *) malloc(sizeof(char) * char_nbr);
		read(filedes, map_table[i], char_nbr);
		i++;
	}
	return (map_table);
}

t_info	*read_from_file(char *file_name)
{
	int		filedes;
	int		fd;
	int		i;
	char	*map_info_char;
	t_info	*info;

	fd = open (file_name, O_RDONLY);
	filedes = open(file_name, O_RDONLY);
	info = malloc(sizeof(t_info));
	i = read_line(filedes);
	map_info_char = (char *) malloc(sizeof(char) * i);
	read(fd, map_info_char, i);
	i = read_line(filedes);
	map_info(info, map_info_char);
	info->matrix = create_map(info->satir_sayisi, i, fd);
	info->satir_uzunluk = i;
	free(map_info_char);
	close(fd);
	close(filedes);
	return (info);
}
