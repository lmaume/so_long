/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:42:40 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/05 18:57:20 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../printf/libft/libft.h"
# include "../printf/libftprintf.h"
# include "../struct.h"
# include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

//? GAMEPLAY PROTO

void	ft_hook(void* param);
int		open_window(void);

#endif