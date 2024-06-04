/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:16:08 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/04 19:32:35 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool is_all_ok(char **map)
{
	if (is_exit_valid == false)
		return (false);
	if (is_player_valid == false)
		return (false);
	if (is_collectible_valid == false)
		return (false);
	if (is_rectangle == false)
		return (false);
	return (true);
}

bool	is_rectangle(char **map)
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
				break;
			return (false);
		}
	}
	return (true);
}

static bool	is_exit_valid(char **map)
{
	if (ft_count_selected_char_in_tab(map, 'E') != 1)
		return (false);
	return (true);
}

static bool	is_player_valid(char **map)
{
	if (ft_count_selected_char_in_tab(map, 'P') != 1)
		return (false);
	return (true);
}

static bool	is_collectible_valid(char **map)
{
	if (ft_count_selected_char_in_tab(map, 'P') > 0)
		return (true);
	return (false);
}
