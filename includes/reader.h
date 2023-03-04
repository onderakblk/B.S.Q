/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:24:23 by oakbulak          #+#    #+#             */
/*   Updated: 2023/02/24 01:31:29 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# define MAX_INT 2147483647
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "types.h"
# include "error_handler.h"

t_info	*map_info(t_info *info, char *frst_line);
int		read_line(int fd);
char	**create_map(int line_nbr, int char_nbr, int filedes);
t_info	*read_from_file(char *file_name);
#endif
