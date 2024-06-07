/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:49:04 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/07 16:43:55 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

void ft_hook(void* param)
{
	t_map	*infomap;

	infomap = (t_map *)param;
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(infomap->mlx);
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_UP))
		infomap->sprites.player->instances[0].y -= 5;
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_DOWN))
		infomap->sprites.player->instances[0].y += 5;
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_LEFT))
		infomap->sprites.player->instances[0].x -= 5;
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_RIGHT))
		infomap->sprites.player->instances[0].x += 5;
}
