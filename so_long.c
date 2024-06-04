/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:07:13 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/04 19:12:18 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	info_map;
	int		i;

	i = 0;
	if (argv[1] == NULL || argc < 2)
		return (0);
	info_map.map = map_init(argv[1]);
	print_map(info_map.map);
}
