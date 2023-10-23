/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:54:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/16 07:16:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(void *const mlx_ptr, t_data *const dest)
{
	dest->img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (dest->img == NULL)
	{
		print_format_error(strerror(errno));
		return ;
	}
	dest->addr = mlx_get_data_addr(dest->img, &dest->bits_per_pixel,
			&dest->line_length, &dest->endian);
	if (dest->addr == NULL)
		print_format_error(strerror(errno));
}