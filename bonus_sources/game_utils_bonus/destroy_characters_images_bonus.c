/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_characters_images_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:44:38 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 17:49:18 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_hedegehog_images(t_game_data *game_data)
{
	if (game_data->images_data.hedgehog_left_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.hedgehog_left_img.img_ptr);
	if (game_data->images_data.hedgehog_right_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.hedgehog_right_img.img_ptr);
	if (game_data->images_data.hedgehog_exit_right_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.hedgehog_exit_right_img.img_ptr);
	if (game_data->images_data.hedgehog_exit_left_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.hedgehog_exit_left_img.img_ptr);
}

void	destroy_bear_images(t_game_data *game_data)
{
	if (game_data->images_data.bear_right_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.bear_right_img.img_ptr);
	if (game_data->images_data.bear_left_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.bear_left_img.img_ptr);
	if (game_data->images_data.bear_exit_right_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.bear_exit_right_img.img_ptr);
	if (game_data->images_data.bear_exit_left_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.bear_exit_left_img.img_ptr);
}

void	destroy_crab_images(t_game_data *game_data)
{
	if (game_data->images_data.crab_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.crab_img.img_ptr);
	if (game_data->images_data.crab_exit_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.crab_exit_img.img_ptr);
}

void	destroy_sanic_images(t_game_data *game_data)
{
	if (game_data->images_data.sanic_right_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.sanic_right_img.img_ptr);
	if (game_data->images_data.sanic_left_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.sanic_left_img.img_ptr);
	if (game_data->images_data.sanic_exit_right_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.sanic_exit_right_img.img_ptr);
	if (game_data->images_data.sanic_exit_left_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.sanic_exit_left_img.img_ptr);
}
