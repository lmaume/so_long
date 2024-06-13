/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:19:17 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/13 17:08:05 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

void	put_sprite(t_map *infomap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (infomap->map[i] != NULL)
	{
		while (infomap->map[i][j] != '\0')
		{
			if (infomap->map[i][j] == 'E')
			{
				if (mlx_image_to_window(infomap->mlx, \
				infomap->sprites.exit, j * 64, i * 64) == -1)
					mlx_close_window(infomap->mlx);
				infomap->exit_x = j;
				infomap->exit_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (mlx_image_to_window(infomap->mlx, infomap->sprites.player, \
							infomap->p_x * 64, infomap->p_y * 64) == -1)
		mlx_close_window(infomap->mlx);
}

void	delete_all_textures(t_map *infomap)
{
	mlx_delete_texture(infomap->sprites.p_texture);
	mlx_delete_texture(infomap->sprites.exit_texture);
	mlx_delete_texture(infomap->sprites.coin_texture);
	mlx_delete_texture(infomap->sprites.wall_texture);
	mlx_delete_texture(infomap->sprites.floor_texture);
}

t_coins	*coin_to_del(t_map *infomap)
{
	t_coins	*index;

	index = infomap->lst_coins;
	while (index != NULL)
	{
		if (index->c_x == infomap->p_x && index->c_y == infomap->p_y)
			return (index);
		index = index->next;
	}
	return (index);
}

bool	is_player_on_coin(t_map *infomap)
{
	t_coins	*index;

	index = infomap->lst_coins;
	while (index != NULL)
	{
		if (index->c_x == infomap->p_x && index->c_y == infomap->p_y)
		{
			return (true);
		}
		index = index->next;
	}
	return (false);
}

bool	is_win(t_map *infomap, int x, int y)
{
	if ((x == infomap->exit_x && y == infomap->exit_y) && \
		ft_count_selected_char_in_tab(infomap->map, 'C') == 0)
	{
		printf("you won\n");
		mlx_close_window(infomap->mlx);
		return (true);
	}
	return (false);
}
