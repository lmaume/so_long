/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:05:19 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/12 14:31:34 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

static t_coins	*ft_newcoin(void *content, int x, int y)
{
	t_coins	*bloc;

	bloc = ft_calloc(sizeof(t_coins), 1);
	bloc->coin = content;
	bloc->c_x = x;
	bloc->c_y = y;
	return (bloc);
}

static void	ft_coinadd_back(t_coins **lst, t_coins *new)
{
	t_coins	*bloc;

	bloc = *lst;
	while (bloc->next != NULL)
		bloc = bloc->next;
	bloc->next = new;
	new->next = NULL;
}

void	ft_del_one_coin(t_map *infomap, t_coins **lst, t_coins *to_del)
{
	t_coins	*bloc;

	bloc = *lst;
	if (bloc == to_del)
	{
		(*lst) = (*lst)->next;
		mlx_delete_image(infomap->mlx, bloc->coin);
		return (free(to_del));
	}
	while (bloc->next != to_del)
		bloc = bloc->next;
	if (to_del->next == NULL)
	{
		mlx_delete_image(infomap->mlx, bloc->next->coin);
		free(to_del);
		bloc->next = NULL;
		return ;
	}
	else
		bloc->next = bloc->next->next;
	mlx_delete_image(infomap->mlx, to_del->coin);
	return (free(to_del));
}

void	texture_to_coin(t_map *infomap, mlx_texture_t *coin)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 1;
	count = 0;
	while (infomap->map[i] != NULL)
	{	
		while (infomap->map[i][j] != '\0')
		{
			if (infomap->map[i][j] == 'C' && count == 0)
			{
				infomap->lst_coins = \
				ft_newcoin(mlx_texture_to_image(infomap->mlx, coin), j, i);
				count++;
			}
			else if (infomap->map[i][j] == 'C' && count > 0)
				ft_coinadd_back(&infomap->lst_coins, \
				ft_newcoin(mlx_texture_to_image(infomap->mlx, coin), j, i));
			j++;
		}
		j = 0;
		i++;
	}
}

int	display_coins(t_map *infomap)
{
	t_coins	*index;
	int		i;
	int		j;

	i = 0;
	j = 0;
	index = infomap->lst_coins;
	while (i < infomap->map_y && index != NULL)
	{
		while (j < infomap->map_x - 1 && index != NULL)
		{
			j++;
			if (infomap->map[i][j] == 'C')
			{
				if (mlx_image_to_window(infomap->mlx, \
				index->coin, (j * 64), (i * 64)) == -1)
					return (EXIT_FAILURE);
				index = index->next;
			}
		}
		j = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}
