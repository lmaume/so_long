/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:51:56 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/10 16:09:03 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_lst_coins
{
	mlx_image_t	*coin;
	struct s_lst_coins *next;
}						t_coins;

typedef struct s_lst_tiles
{
	mlx_image_t	*tile;
	struct s_lst_tiles *next;
}					t_tile;

typedef struct	s_sprites
{
	mlx_texture_t	*p_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*coin_texture;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*player;
	mlx_image_t		*exit;
}				t_sprites, t_player;

typedef struct	s_info_map
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_sprites	sprites;
	t_coins		*lst_coins;
	t_tile		*lst_tiles;
	char		**map;
	char		*filename;
	int			p_x;
	int			p_y;
	int			m_x;
	int			m_y;
}				t_map;

#endif