/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:39:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/16 14:22:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_map *const map)
{
	map->player = get_player(map);
}

static t_key	*init_keys(void)
{
	static t_key	keys[KEY_COUNT] = {
	{.key_value = K_M, .pressure = false},
	{.key_value = K_W, .pressure = false},
	{.key_value = K_A, .pressure = false},
	{.key_value = K_S, .pressure = false},
	{.key_value = K_D, .pressure = false},
	{.key_value = K_LEFT, .pressure = false},
	{.key_value = K_RIGHT, .pressure = false},
	{.key_value = K_SPACE, .pressure = false},
	{.key_value = K_ESC, .pressure = false}
	};

	return (keys);
}

static void	init_mlx(t_win *const window)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
	{
		print_format_error(MLX_ERROR);
		return ;
	}
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (window->win_ptr == NULL)
	{
		print_format_error(MLX_ERROR);
		return ;
	}
	init_data(window->mlx_ptr, &window->data);
}

void	init_window(
	t_win *const window,
	char *const *const file_content
	)
{
	ssize_t	offset;

	window->map = NULL;
	window->win_ptr = NULL;
	init_mlx(window);
	offset = build_config(&(window->config),
			file_content, window->mlx_ptr, window->win_ptr);
	if (offset == INVALID_OFFSET)
		return ;
	offset += count_empty_lines(file_content + offset);
	init_map_in_window(window, offset, file_content);
	if (window->map != NULL)
	{
		if (BONUS)
			init_sprites(window->map, &(window->config));
		init_player(window->map);
		window->keys = init_keys();
		window->mod = E_STD;
	}
	window->is_mouse_in_window = false;
}
