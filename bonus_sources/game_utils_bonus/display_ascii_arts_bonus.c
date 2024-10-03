/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ascii_arts_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:21:46 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:51:09 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_hedgehog(char *color)
{
	ft_printf("%s", color);
	ft_printf("\n");
	ft_printf("        .|||||||||.          .|||||||||.\n");
	ft_printf("       |||||||||||||        |||||||||||||\n");
	ft_printf("      |||||||||||' .\\      /\\. `|||||||||||\n");
	ft_printf("      `||||||||||_,__o    o__,_||||||||||'%s\n", KNRM);
}

void	display_book(char *color)
{
	ft_printf("%s", color);
	ft_printf("\n");
	ft_printf("        __...--~~~~~-._   _.-~~~~~--...__\n");
	ft_printf("      //               `V'               \\\\ \n");
	ft_printf("     //                 |                 \\\\ \n");
	ft_printf("    //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\ \n");
	ft_printf("   //__.....----~~~~._\\ | /_.~~~~----.....__\\\\\n");
	ft_printf("  ====================\\\\|//====================%s\n\n", KNRM);
	ft_printf("\n");
}
