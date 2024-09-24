/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:10:09 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/24 16:51:14 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	launch_game(t_game_data *game_data)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int 	img_width;
	int 	img_height;

	(void)game_data;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (EXIT_FAILURE);
	win_ptr = mlx_new_window(mlx_ptr, 700, 900, "Test");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./assets/test_redim.xpm",
			&img_width, &img_height);
	if (img_ptr == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		return (EXIT_FAILURE);
	}
	if (win_ptr == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		return (EXIT_FAILURE);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
	mlx_loop(mlx_ptr);
	return (EXIT_SUCCESS);
}
