/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:42:40 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/06 18:02:50 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

# include "../printf/libft/libft.h"
# include "../printf/libftprintf.h"
# include "../struct.h"
# include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512

//? GAMEPLAY PROTO

void	ft_hook(void* param);
int		open_window(t_map infomap);

#endif