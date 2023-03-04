/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:24:23 by oakbulak          #+#    #+#             */
/*   Updated: 2023/02/24 01:31:29 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H
# include <unistd.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_strlen_with_point(char *str, char stop_point);
char	*ft_strdup(char *src);
void	ft_putstr(char *str);
void	print_error(char *message);
#endif
