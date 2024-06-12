/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:06:57 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/12 17:31:13 by lmaume           ###   ########.fr       */
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
void	get_map_size(t_map *infomap);
bool	is_all_ok(int x, int y, char **map, t_map *infomap);
bool	is_walls_valid(char **map);
bool	is_too_big(t_map *infomap);
void	player_pos(t_map *infomap);
int		pathfinding(int x, int y, char **map);

//? MAP INITIALISATION
int		count_file_size(char *filename);
char	**map_init(char *filename);
void	print_map(char **map);

#endif