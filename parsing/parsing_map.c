/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:16:08 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/12 16:50:45 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_rectangle(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	if (map == NULL)
		return (false);
	len = ft_strlen(map[i]);
	while (map[i + 1] != NULL)
	{
		if (len == ft_strlen(map[i + 1]))
			i++;
		else
		{
			if (map[i + 2] == NULL && (len == ft_strlen(map[i + 1]) + 1))
				break ;
			ft_printf("Map is not rectangle.\n");
			return (false);
		}
	}
	return (true);
}

static bool	is_exit_valid(char **map)
{
	if (ft_count_selected_char_in_tab(map, 'E') != 1)
	{
		ft_printf("No exit or more than one.\n");
		return (false);
	}
	return (true);
}

static bool	is_player_valid(char **map)
{
	if (ft_count_selected_char_in_tab(map, 'P') != 1)
	{
		ft_printf("No player or more than one.\n");
		return (false);
	}
	return (true);
}

bool	is_collectible_valid(char **map)
{
	if (ft_count_selected_char_in_tab(map, 'C') > 0)
	{
		return (true);
	}
	ft_printf("No collectibles.\n");
	return (false);
}

bool	is_all_ok(int x, int y, char **map, t_map *infomap)
{
	if (is_rectangle(map) == false)
		return (false);
	if (is_exit_valid(map) == false)
		return (false);
	if (is_player_valid(map) == false)
		return (false);
	if (is_collectible_valid(map) == false)
		return (false);
	if (is_too_big(infomap) == false)
		return (false);
	if (is_walls_valid(map) == false)
	{
		ft_printf("Map is not surrounded by walls.\n");
		return (false);
	}
	if (ft_count_selected_char_in_tab(map, 'C') + 1 != pathfinding(x, y, map))
	{
		ft_printf("Map is not playable.\n");
		return (false);
	}
	return (true);
}
