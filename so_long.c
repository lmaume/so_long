/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:07:13 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/13 14:51:54 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_lists(t_map *infomap)
{
	t_coins	*temp_coin;
	t_tile	*temp_tile;

	while (infomap->lst_coins != NULL)
	{
		temp_coin = infomap->lst_coins->next;
		if (infomap->lst_coins->coin != NULL)
			mlx_delete_image(infomap->mlx, infomap->lst_coins->coin);
		free(infomap->lst_coins);
		infomap->lst_coins = temp_coin;
	}
	while (infomap->lst_tiles != NULL)
	{
		temp_tile = infomap->lst_tiles->next;
		if (infomap->lst_tiles->tile != NULL)
			mlx_delete_image(infomap->mlx, infomap->lst_tiles->tile);
		free(infomap->lst_tiles);
		infomap->lst_tiles = temp_tile;
	}
}

int	main(int argc, char **argv)
{
	t_map	info_map;
	char	**map_copy;
	int		i;

	i = 0;
	if (argv[1] == NULL || ft_strlen(argv[1]) < 5 || argc < 2)
		return (0);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		return (ft_printf("Map extension is not .ber.\n"));
	map_copy = map_init(argv[1]);
	info_map.map = map_init(argv[1]);
	if (map_copy == NULL || info_map.map == NULL)
		return (1);
	player_pos(&info_map);
	get_map_size(&info_map);
	if (is_all_ok(info_map.p_x, info_map.p_y, map_copy, &info_map) == false)
	{
		free_tab(info_map.map);
		free_tab(map_copy);
		return (0);
	}
	open_window(info_map);
	free_tab(map_copy);
	free_tab(info_map.map);
	return (0);
}
