/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:40:20 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/07 18:30:21 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

// static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// static void ft_randomize(void* param)
// {
// 	t_map	*infomap;

// 	infomap = (t_map *)param;
// 	for (uint32_t i = 0; i < infomap->image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < infomap->image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(infomap->image, i, y, color);
// 		}
// 	}
// }


int	file_to_image(t_map infomap)
{
	infomap.sprites.p_texture = mlx_load_png("gameplay/textures/player.png");
	if (infomap.sprites.p_texture == NULL)
		return (EXIT_FAILURE);

	// Convert texture to a displayable image
	infomap.sprites.player = mlx_texture_to_image(infomap.mlx, infomap.sprites.p_texture);
	if (!infomap.sprites.player)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	open_window(t_map infomap)
{

	
	// Gotta error check this stuff
	if (!(infomap.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return(EXIT_FAILURE);
	
	
	
	
	
	// Display the image
	if (mlx_image_to_window(infomap.mlx, infomap.sprites.player, 150, 150) < 0)
		return (EXIT_FAILURE);

	if (!(infomap.image = mlx_new_image(infomap.mlx, 128, 128)))
	{
		mlx_close_window(infomap.mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(infomap.mlx, infomap.image, 50, 50) == -1)
	{
		mlx_close_window(infomap.mlx);
		return (EXIT_FAILURE);
	}
	// mlx_loop_hook(infomap.mlx, &ft_randomize, (void *)&infomap);
	mlx_loop_hook(infomap.mlx, &ft_hook, (void *)&infomap);

	mlx_loop(infomap.mlx);

	mlx_delete_image(infomap.mlx, infomap.sprites.player);
	mlx_delete_texture(infomap.sprites.p_texture);
	mlx_terminate(infomap.mlx);
	return (EXIT_SUCCESS);
}
