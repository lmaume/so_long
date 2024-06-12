/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:44:03 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/12 14:02:06 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	player_pos(t_map *infomap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (infomap->map[i] != NULL)
	{
		j = 0;
		while (infomap->map[i][j] != '\0' && infomap->map[i][j] != 'P')
			j++;
		if (infomap->map[i][j] == 'P')
			break ;
		i++;
	}
	infomap->p_x = j;
	infomap->p_y = i;
}

bool	is_walls_valid(char **map)
{
	int		i;

	i = 1;
	if (map == NULL)
		return (false);
	if (is_line_full_of_c(map[0], '1') == false)
		return (false);
	while (map[i + 2] != NULL)
	{
		if (is_started_and_finished_by_c(map[i], '1') == false)
			return (false);
		i++;
	}
	if (is_line_full_of_c(map[i + 1], '1') == false)
		return (false);
	return (true);
}

int	pathfinding(int x, int y, char **map)
{
	int	end;

	end = 0;
	if (map[x][y] == 'C' || map[x][y] == 'E')
		++end;
	map[x][y] = '1';
	if (map[x + 1][y] != '1')
		end += pathfinding(x + 1, y, map);
	if (map[x - 1][y] != '1')
		end += pathfinding(x - 1, y, map);
	if (map[x][y + 1] != '1')
		end += pathfinding(x, y + 1, map);
	if (map[x][y - 1] != '1')
		end += pathfinding(x, y - 1, map);
	return (end);
}
