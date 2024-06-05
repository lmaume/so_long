/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:06:57 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/05 16:47:00 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSING_H
# define PARSING_H

# include "../struct.h"
# include "../printf/libft/libft.h"
# include "../printf/libftprintf.h"
# include "../get_next_line/get_next_line.h"
# include <stdbool.h>

//? MAP VERIFICATIONS
bool 	is_all_ok(int x, int y, char **map);
bool	is_walls_valid(char **map);
void	player_pos(t_map *infomap);
int     pathfinding(int x, int y, char **map);

//? MAP INITIALISATION
int		count_file_size(char *filename);
char	**map_init(char *filename);
void	print_map(char **map);

#endif