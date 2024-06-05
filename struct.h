/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:51:56 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/05 14:52:44 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_info_map
{
	char	*filename;
	char	**map;
	int		p_x;
	int		p_y;
}		t_map;

#endif