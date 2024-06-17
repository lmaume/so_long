/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:26:00 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/17 11:01:25 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**map_init(char *filename)
{
	return (ft_file_to_tab(filename));
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
	if (bloc == NULL)
		return (NULL);
	bloc->tile = content;
	return (bloc);
}

void	ft_tileadd_back(t_tile **lst, t_tile *new)
{
	t_tile	*bloc;

	if (new == NULL)
		return ;
	bloc = *lst;
	while (bloc->next != NULL)
	{
		bloc = bloc->next;
	}
	bloc->next = new;
	new->next = NULL;
}

bool	is_too_big(t_map *infomap)
{
	if (infomap->map_x > 60 || infomap->map_y > 30)
	{
		ft_printf("Map is to big.\n");
		return (false);
	}
	return (true);
}
