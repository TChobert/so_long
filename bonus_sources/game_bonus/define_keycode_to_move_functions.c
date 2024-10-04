/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_keycode_to_move_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:40:36 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 16:44:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	define_keycode_to_move_function(int keycode)
{
	int	key_function_call;

	key_function_call = -1;
	if (keycode == W_KEY)
		key_function_call = KEY_W_INDEX;
	else if (keycode == A_KEY)
		key_function_call = KEY_A_INDEX;
	else if (keycode == S_KEY)
		key_function_call = KEY_S_INDEX;
	else if (keycode == D_KEY)
		key_function_call = KEY_D_INDEX;
	else if (keycode == ESC_KEY)
		key_function_call = KEY_ESC_INDEX;
	return (key_function_call);
}

int	reverse_define_keycode_to_move_function(int keycode)
{
	int	key_function_call;

	key_function_call = -1;
	if (keycode == W_KEY)
		key_function_call = KEY_D_INDEX;
	else if (keycode == A_KEY)
		key_function_call = KEY_S_INDEX;
	else if (keycode == S_KEY)
		key_function_call = KEY_A_INDEX;
	else if (keycode == D_KEY)
		key_function_call = KEY_W_INDEX;
	else if (keycode == ESC_KEY)
		key_function_call = KEY_ESC_INDEX;
	return (key_function_call);
}
