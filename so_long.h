/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:22:45 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/04 18:24:53 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/libft/libft.h"
# include "printf/libftprintf.h"
# include "parsing/parsing.h"

# include "mlx.h"
# include <sys/types.h> //V
# include <sys/stat.h> // V
# include <fcntl.h> //open, close
# include <errno.h> //error gestion
# include <string.h> //strerror
# include <stdio.h> //perror, printf de test
# include <stdlib.h>  //malloc, free
# include <unistd.h> //write, read, exit


typedef struct	s_info_map
{
	char	*filename;
	char	**map;
}		t_map;

// enum e_errors
// {
// 	ERROR = -1
// };

#endif