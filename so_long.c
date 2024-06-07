/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:07:13 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/07 14:58:10 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	info_map;
	char	**map_copy;
	int		i;

	i = 0;
	if (argv[1] == NULL || ft_strlen(argv[1]) < 5 || argc < 2)
		return (0);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
	{
		ft_printf("Map extension is not .ber.\n");
		return (0);
	}
	map_copy = map_init(argv[1]);
	info_map.map = map_init(argv[1]);
	print_map(info_map.map);
	player_pos(&info_map);
	if (is_all_ok(info_map.p_x, info_map.p_y, map_copy) == false)
		free_tab(map_copy);
	open_window(info_map);

	free_tab(map_copy);
	free_tab(info_map.map);
}
