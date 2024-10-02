/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:43:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/02 19:34:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_hedgehog(void)
{
	ft_printf("\n");
	ft_printf("      .|||||||||.          .|||||||||.\n");
	ft_printf("     |||||||||||||        |||||||||||||\n");
	ft_printf("    |||||||||||' .\\      /\\. `|||||||||||\n");
	ft_printf("    `||||||||||_,__o    o__,_||||||||||'\n");
}

static void	display_book(char *color)
{
	ft_printf("%s", color);
	ft_printf("\n");
	ft_printf("      __...--~~~~~-._   _.-~~~~~--...__\n");
	ft_printf("    //               `V'               \\\\ \n");
	ft_printf("   //                 |                 \\\\ \n");
	ft_printf("  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\ \n");
	ft_printf(" //__.....----~~~~._\\ | /_.~~~~----.....__\\\\\n");
	ft_printf("====================\\\\|//====================%s\n\n", KNRM);
	ft_printf("\n");
}

static void	display_end_message(t_game_data *game_data)
{
	if (game_data->images_data.is_images_loaded != false)
	{
		if (game_data->map_data.items_values.collectibles_number >= 0
			&& game_data->map_data.items_values.exit_number > 0)
		{
			ft_printf("You made %d moves. See you !\n",
				game_data->character_data.moves_counter);
		}
		else if (game_data->map_data.items_values.collectibles_number == 0
			&& game_data->map_data.items_values.exit_number == 0)
		{
			ft_printf("You made %d moves. Well done !\n",
				game_data->character_data.moves_counter);
			display_hedgehog();
			display_book(KMAG);
		}
	}
}

static void	destroy_character_images(t_game_data *game_data)
{
	if (game_data->images_data.character_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.character_img.img_ptr);
	if (game_data->images_data.character_right_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.character_right_img.img_ptr);
	if (game_data->images_data.character_exit_right_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.character_exit_right_img.img_ptr);
	if (game_data->images_data.character_exit_left_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.character_exit_left_img.img_ptr);
}

static	void	destroy_game_images(t_game_data *game_data)
{
	destroy_character_images(game_data);
	if (game_data->images_data.collectible_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.collectible_img.img_ptr);
	if (game_data->images_data.exit_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.exit_img.img_ptr);
	if (game_data->images_data.wall_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.wall_img.img_ptr);
	if (game_data->images_data.floor_img.img_ptr != NULL)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr,
			game_data->images_data.floor_img.img_ptr);
}

t_move_status	close_game(t_game_data *game_data)
{
	const bool	is_images_loaded = game_data->images_data.is_images_loaded;

	display_end_message(game_data);
	destroy_game_images(game_data);
	if (game_data->mlx_data.win_ptr != NULL)
		mlx_destroy_window(game_data->mlx_data.mlx_ptr,
			game_data->mlx_data.win_ptr);
	if (game_data->mlx_data.mlx_ptr != NULL)
	{
		mlx_destroy_display(game_data->mlx_data.mlx_ptr);
		free(game_data->mlx_data.mlx_ptr);
	}
	ft_free_and_null(game_data->map_data.map_array);
	if (is_images_loaded == false)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
