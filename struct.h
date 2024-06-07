/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:51:56 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/07 17:16:43 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_sprite_coins
{
	mlx_image_t	*coin;
	
	struct s_sprite_coins *next;
}	t_coins;

typedef struct	s_sprites
{
	mlx_texture_t*	p_texture;
	
	mlx_image_t*	player;
	mlx_image_t*	exit;
}				t_sprites, t_player;

typedef struct	s_info_map
{
	mlx_image_t	*image;
	mlx_t		*mlx;
	t_sprites	sprites;
	t_coins		coins;
	char		*filename;
	char		**map;
	int			p_x;
	int			p_y;
}				t_map;

#endif