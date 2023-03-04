/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:24:23 by oakbulak          #+#    #+#             */
/*   Updated: 2023/02/24 01:31:29 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reader.h"
#include <stdio.h>

typedef struct t_point
{
	int	x;
	int	y;
}	t_point;

int	len(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

int	**str_to_int(char **str, int height, int width, char obstacle)
{
	int	**result;
	int	i;
	int	j;

	result = malloc(height * sizeof(int *));
	i = 0;
	while (i < height)
	{
		result[i] = malloc(width * sizeof(int));
		j = 0;
		while (j < width)
		{
			if (str[i][j] == obstacle)
			{
				result[i][j] = 0;
			}
			else
			{
				result[i][j] = 1;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void	islemi_yap(t_info *self, int **yeni_matrix)
{
	t_point	enbuyuk_width_point;
	int		enbuyuksonuc;
	int		y;
	int		x;
	int		sonuc;

	enbuyuksonuc = 0;
	y = 1;
	while (y < self->satir_sayisi)
	{
		x = 1;
		while (x < self->satir_uzunluk)
		{
			if (yeni_matrix[y][x] != 0)
			{
				sonuc = MIN(MIN(yeni_matrix[y][x - 1], yeni_matrix[y - 1][x]),
						yeni_matrix[y - 1][x - 1]) + 1;
				yeni_matrix[y][x] = sonuc;
				if (sonuc > enbuyuksonuc)
				{
					enbuyuksonuc = sonuc;
					enbuyuk_width_point.x = x;
					enbuyuk_width_point.y = y;
				}
			}
			x++;
		}
		y++;
	}
	self->max_x = enbuyuk_width_point.x;
	self->max_y = enbuyuk_width_point.y;
	self->max_uzunluk = enbuyuksonuc;
}

void	print_matrix(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->satir_sayisi)
	{
		x = 0;
		while (x < info->satir_uzunluk)
		{
			if (y > info->max_y - info->max_uzunluk
				&& y < info->max_y
				&&x > info->max_x - info->max_uzunluk
				&& x < info->max_x + 1)
				write(1, "X", 1);
			else
				write(1, &info->matrix[y][x], 1);
			x++;
		}
		y++;
	}	
}

int	main(int agc, char **agv)
{
	t_info	*info;
	int		**sayi_matrix;

	while (agc > 0)
	{
		agc--;
		info = read_from_file(agv[agc]);
		sayi_matrix = str_to_int(info->matrix, info->satir_sayisi,
				info->satir_uzunluk, info->engel);
		islemi_yap(info, sayi_matrix);
		print_matrix(info);
		if (agc != 1)
			write(1, "\n", 1);
	}
	return (0);
}
