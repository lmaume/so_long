/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:42:40 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/10 16:08:25 by lmaume           ###   ########.fr       */
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

//? GAMEPLAY PROTO
int		open_window(t_map infomap);
int		file_to_image(t_map *infomap);
void	get_map_size(t_map *infomap);

//? PLAYER MOVEMENTS
void	ft_hook(void *param);
void	move_up(t_map *infomap);
void	move_down(t_map *infomap);
void	move_left(t_map *infomap);\
void	move_right(t_map *infomap);

//? TEXTURE MAP GESTION
t_tile	*ft_tilenew(void *content);
void	ft_tileadd_back(t_tile **lst, t_tile *new);

#endif