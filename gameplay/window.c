/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:40:20 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/17 10:52:21 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

void	texture_to_list(t_map *infomap, t_texture *wall, t_texture *floor)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	infomap->lst_tiles = ft_tilenew(mlx_texture_to_image(infomap->mlx, wall));
	while (infomap->map[i] != NULL)
	{
		while (infomap->map[i][j] != '\0')
		{
			if (infomap->map[i][j] == '1')
				ft_tileadd_back(&infomap->lst_tiles, \
				ft_tilenew(mlx_texture_to_image(infomap->mlx, wall)));
			else
				ft_tileadd_back(&infomap->lst_tiles, \
				ft_tilenew(mlx_texture_to_image(infomap->mlx, floor)));
			j++;
		}
		j = 0;
		i++;
	}
}

int	display_map(t_map *infomap)
{
	t_tile	*index;
	int		i;
	int		j;

	i = 0;
	j = 0;
	index = infomap->lst_tiles;
	while (i < infomap->map_y && index->next != NULL)
	{
		if (mlx_image_to_window(infomap->mlx, index->tile, \
									(j * 64), (i * 64)) == -1)
			return (EXIT_FAILURE);
		while (j < infomap->map_x - 1 && index->next != NULL)
		{
			index = index->next;
			j++;
			if (mlx_image_to_window(infomap->mlx, index->tile, \
										(j * 64), (i * 64)) == -1)
				return (EXIT_FAILURE);
		}
		index = index->next;
		j = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	file_to_image(t_map *infomap)
{
	infomap->sprites.p_texture = mlx_load_png("gameplay/textures/player.png");
	if (infomap->sprites.p_texture == NULL)
		return (EXIT_FAILURE);
	infomap->sprites.wall_texture = mlx_load_png("gameplay/textures/wall.png");
	if (infomap->sprites.wall_texture == NULL)
		return (EXIT_FAILURE);
	infomap->sprites.floor_texture = \
	mlx_load_png("gameplay/textures/tile.png");
	if (infomap->sprites.floor_texture == NULL)
		return (EXIT_FAILURE);
	infomap->sprites.coin_texture = mlx_load_png("gameplay/textures/coin.png");
	if (infomap->sprites.coin_texture == NULL)
		return (EXIT_FAILURE);
	infomap->sprites.exit_texture = mlx_load_png("gameplay/textures/exit.png");
	if (infomap->sprites.exit_texture == NULL)
		return (EXIT_FAILURE);
	infomap->sprites.exit = \
	mlx_texture_to_image(infomap->mlx, infomap->sprites.exit_texture);
	if (!infomap->sprites.exit)
		return (EXIT_FAILURE);
	infomap->sprites.player = \
	mlx_texture_to_image(infomap->mlx, infomap->sprites.p_texture);
	if (!infomap->sprites.player)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	open_window(t_map infomap)
{
	infomap.mlx = mlx_init((infomap.map_x - 1) * 64, \
					infomap.map_y * 64, "so_long", false);
	if (file_to_image(&infomap) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	texture_to_list(&infomap, infomap.sprites.wall_texture, \
								infomap.sprites.floor_texture);
	if (display_map(&infomap) == -1)
	{
		mlx_close_window(infomap.mlx);
		return (close_window(&infomap), EXIT_FAILURE);
	}
	texture_to_coin(&infomap, infomap.sprites.coin_texture);
	if (display_coins(&infomap) == -1)
	{
		mlx_close_window(infomap.mlx);
		return (close_window(&infomap), EXIT_FAILURE);
	}
	put_sprite(&infomap);
	infomap.moves = 0;
	mlx_loop_hook(infomap.mlx, &ft_hook, (void *)&infomap);
	mlx_loop(infomap.mlx);
	close_window(&infomap);
	mlx_terminate(infomap.mlx);
	return (EXIT_SUCCESS);
}

void	close_window(t_map *infomap)
{
	mlx_delete_image(infomap->mlx, infomap->sprites.player);
	mlx_delete_image(infomap->mlx, infomap->sprites.exit);
	free_lists(infomap);
	delete_all_textures(infomap);
}
