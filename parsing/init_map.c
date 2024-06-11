/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:26:00 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/11 14:09:10 by lmaume           ###   ########.fr       */
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

void	get_map_size(t_map *infomap)
{
	int	i;

	i = 0;
	if (infomap->map[0] != NULL)
		infomap->map_x = ft_strlen(infomap->map[0]);
	while (infomap->map[i] != NULL)
		i++;
	infomap->map_y = i;
}

t_tile	*ft_tilenew(void *content)
{
	t_tile	*bloc;
	
	bloc = ft_calloc(sizeof(t_tile), 1);
	bloc->tile = content;
	return (bloc);
}

void	ft_tileadd_back(t_tile **lst, t_tile *new)
{
	t_tile	*bloc;
	
	bloc = *lst;
	while (bloc->next != NULL)
	{
		bloc = bloc->next;
	}
	bloc->next = new;
	new->next = NULL;
}
