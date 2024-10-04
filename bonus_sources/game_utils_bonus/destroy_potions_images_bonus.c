/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_potions_images_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:50:49 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 17:52:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_potions_images(t_game_data *game_data)
{
	if (game_data->images_data.red_potion_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.red_potion_img.img_ptr);
	if (game_data->images_data.green_potion_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.green_potion_img.img_ptr);
	if (game_data->images_data.black_potion_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.black_potion_img.img_ptr);
	if (game_data->images_data.blue_potion_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.blue_potion_img.img_ptr);
	if (game_data->images_data.yellow_potion_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.yellow_potion_img.img_ptr);
}
