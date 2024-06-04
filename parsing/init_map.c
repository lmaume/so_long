/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:26:00 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/04 18:26:21 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**map_init(char *filename)
{
	return (ft_file_to_tab(filename));
}

void print_map(char **map)
{
	ft_print_tab(map);
}
