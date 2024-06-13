/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:54:20 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/13 17:05:56 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_spriteuh
{
	mlx_texture_t		*p_texture;
	mlx_texture_t		*wall_texture;
	mlx_texture_t		*floor_texture;
	mlx_texture_t		*coin_texture;
	mlx_texture_t		*exit_texture;
	mlx_image_t			*player;
	mlx_image_t			*exit;
}						t_sprites;

#endif