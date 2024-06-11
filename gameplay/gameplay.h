/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:42:40 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/11 19:09:32 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

# include "../printf/libft/libft.h"
# include "../printf/libftprintf.h"
# include "../struct.h"
# include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512

//? DISPLAY PROTO
int		open_window(t_map infomap);
int		file_to_image(t_map *infomap);
int		display_coins(t_map *infomap);
void	put_sprite(t_map *infomap);
void	get_map_size(t_map *infomap);
void	texture_to_coin(t_map *infomap);
void	delete_all_textures(t_map *infomap);

//? PLAYER MOVEMENTS
void	ft_hook(void *param);
void	move_up(t_map *infomap);
void	move_down(t_map *infomap);
void	move_left(t_map *infomap);
void	move_right(t_map *infomap);

//? TEXTURE MAP GESTION
t_tile	*ft_tilenew(void *content);
void	ft_tileadd_back(t_tile **lst, t_tile *new);

//? WIN GESTION
t_coins	*coin_to_del(t_map *infomap);
bool	is_player_on_coin(t_map *infomap);
void	ft_del_one_coin(t_map *infomap, t_coins **lst, t_coins *to_del);
bool	is_collectible_valid(char **map);
bool	is_win(t_map *infomap, int x, int y);

void	print_list(t_coins *lst);

#endif