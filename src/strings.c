/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:24:23 by oakbulak          #+#    #+#             */
/*   Updated: 2023/02/24 01:31:29 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/strings.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		ft_putchar(str[index++]);
	write(1, "\n", 1);
}

void	print_error(char *message)
{
	ft_putstr(message);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
/*
char	*ft_strdup(char *src)
{
	int		length;
	char	*result;

	length = 0;
	while (src[length])
		length++;
	result = malloc(sizeof(char) * (length + 1));
	length = 0;
	while (src[length])
	{
		result[length] = src[length];
		length++;
	}
	return (result);
}*/

int	ft_strlen_with_point(char *str, char stop_point)
{
	int	index;

	index = 0;
	while (str[index] && str[index] != stop_point)
		index++;
	return (index);
}
