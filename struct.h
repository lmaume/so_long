/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:51:56 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/13 16:55:20 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "MLX42/include/MLX42/MLX42.h"
# include "sprite.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_lst_coins
{
	mlx_image_t			*coin;
	int					c_x;
	int					c_y;
	struct s_lst_coins	*next;
}						t_coins;

typedef struct s_lst_tiles
{
	mlx_image_t			*tile;
	struct s_lst_tiles	*next;
}						t_tile;
typedef struct s_info_map
{
	mlx_t				*mlx;
	t_sprites			sprites;
	t_coins				*lst_coins;
	t_tile				*lst_tiles;
	char				**map;
	int					moves;
	int					p_x;
	int					p_y;
	int					map_x;
	int					map_y;
	int					exit_x;
	int					exit_y;
}						t_map;

#endif
