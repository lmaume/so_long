/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:49:04 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/12 19:20:03 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

void	ft_hook(void *param)
{
	t_map	*infomap;

	usleep(7000);
	infomap = (t_map *)param;
	if (is_player_on_coin(infomap) == true)
		ft_del_one_coin(infomap, &infomap->lst_coins, coin_to_del(infomap));
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(infomap->mlx);
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_W) && \
	infomap->map[infomap->p_y - 1][infomap->p_x] != '1')
		move_up(infomap);
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_S) && \
	infomap->map[infomap->p_y + 1][infomap->p_x] != '1')
		move_down(infomap);
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_A) && \
	infomap->map[infomap->p_y][infomap->p_x - 1] != '1')
		move_left(infomap);
	if (mlx_is_key_down(infomap->mlx, MLX_KEY_D) && \
	infomap->map[infomap->p_y][infomap->p_x + 1] != '1')
		move_right(infomap);
}

void	move_up(t_map *infomap)
{
	infomap->sprites.player->instances[0].y -= 64;
	infomap->map[infomap->p_y][infomap->p_x] = '0';
	infomap->map[infomap->p_y - 1][infomap->p_x] = 'P';
	infomap->p_y -= 1;
	infomap->moves += 1;
	if (is_win(infomap, infomap->p_x, infomap->p_y) == true)
		return ;
	ft_printf("You moved [%d] time(s)\n", infomap->moves);
}

void	move_down(t_map *infomap)
{
	infomap->sprites.player->instances[0].y += 64;
	infomap->map[infomap->p_y][infomap->p_x] = '0';
	infomap->map[infomap->p_y + 1][infomap->p_x] = 'P';
	infomap->p_y += 1;
	infomap->moves += 1;
	if (is_win(infomap, infomap->p_x, infomap->p_y) == true)
		return ;
	ft_printf("You moved [%d] time(s)\n", infomap->moves);
}

void	move_left(t_map *infomap)
{
	infomap->sprites.player->instances[0].x -= 64;
	infomap->map[infomap->p_y][infomap->p_x] = '0';
	infomap->map[infomap->p_y][infomap->p_x - 1] = 'P';
	infomap->p_x -= 1;
	infomap->moves += 1;
	if (is_win(infomap, infomap->p_x, infomap->p_y) == true)
		return ;
	ft_printf("You moved [%d] time(s)\n", infomap->moves);
}

void	move_right(t_map *infomap)
{
	infomap->sprites.player->instances[0].x += 64;
	infomap->map[infomap->p_y][infomap->p_x] = '0';
	infomap->map[infomap->p_y][infomap->p_x + 1] = 'P';
	infomap->p_x += 1;
	infomap->moves += 1;
	if (is_win(infomap, infomap->p_x, infomap->p_y) == true)
		return ;
	ft_printf("You moved [%d] time(s)\n", infomap->moves);
}
