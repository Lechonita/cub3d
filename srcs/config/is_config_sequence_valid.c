/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:25:37 by jess              #+#    #+#             */
/*   Updated: 2023/11/14 10:44:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_attribute_key(const char *const key)
{
	size_t						i;
	static const char *const	attribute_key[] = {
		NORTH_KEY, SOUTH_KEY,
		WEST_KEY, EAST_KEY,
		FLOOR_KEY, CEIL_KEY,
		DOOR_KEY, SP1_KEY,
		SP2_KEY, SP3_KEY,
		SP4_KEY, SP5_KEY,
		SP6_KEY, SP7_KEY,
		SP8_KEY, DARK_KEY,
		NULL
	};

	i = 0;
	while (i < ATTRIBUTE_COUNT && streq(key, attribute_key[i]) == false)
		i++;
	return (i < ATTRIBUTE_COUNT);
}

static bool	is_sprite_key(const char *const key)
{
	size_t						i;
	static const char *const	attribute_key[] = {
		SP1_KEY, SP2_KEY,
		SP3_KEY, SP4_KEY,
		SP5_KEY, SP6_KEY,
		SP7_KEY, SP8_KEY,
		NULL
	};

	i = 0;
	while (i < SPRITE_KIND_COUNT && streq(key, attribute_key[i]) == false)
		i++;
	return (i < SPRITE_KIND_COUNT);
}

bool	is_sequence_empty(char *const *const sequence)
{
	return (get_size_strs(sequence) == 0);
}

bool	is_sequence_format_valid(char *const *const sequence)
{
	const size_t	size = get_size_strs(sequence);

	return ((size == 2 && is_attribute_key(sequence[0]))
		|| (BONUS && size >= 2 && is_sprite_key(sequence[0])));
}

bool	is_sequence_valid(char *const *const sequence)
{
	return (sequence != NULL && (is_sequence_empty(sequence)
			|| is_sequence_format_valid(sequence)));
}
