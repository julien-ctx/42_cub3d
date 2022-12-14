/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:52:22 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 21:18:58 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_ver_map(t_c c, t_img *img, int color, t_d *data)
{
	if (c.y1 > data->map->tab_x * data->map->wall_size
		|| c.y2 > data->map->tab_x * data->map->wall_size
		|| c.y1 < 0 || c.y2 < 0)
		return ;
	while (c.y1 <= c.y2)
	{
		ft_pixel_put_map(img, (t_point){c.x, c.y1, color}, data);
		c.y1++;
	}
}

void	draw_square(int x, int color, t_d *data)
{
	int	i;

	i = -1;
	while (++i < data->map->wall_size)
		draw_ver_map((t_c){x + i, data->map->y, data->map->y
			+ data->map->wall_size},
			&data->mlx->map, color, data);
}

void	print_tiles(t_d *data)
{
	int	x;
	int	y;

	y = -1;
	data->map->y = 0;
	while (data->tab[++y])
	{
		x = -1;
		data->map->x = 0;
		while (data->tab[y][++x])
		{
			if (data->tab[y][x] == '1')
				draw_square(data->map->x, MAP_WALLS, data);
			else if (data->tab[y][x] != ' ')
				draw_square(data->map->x, MAP_FLOOR, data);
			else
				draw_square(data->map->x, MAP_SPACES, data);
			data->map->x += data->map->wall_size;
		}
		data->map->y += data->map->wall_size;
	}
}

void	print_pos(t_d *data)
{
	int	i;
	int	j;

	i = -data->map->wall_size / 2;
	while (i < data->map->wall_size / 2)
	{
		j = -data->map->wall_size / 2;
		while (j < data->map->wall_size / 2)
		{
			ft_pixel_put(&data->mlx->map,
				floor(data->pos_x * (double)data->map->wall_size) + i,
				floor(data->pos_y * (double)data->map->wall_size) + j, PLAYER);
			j++;
		}
		i++;
	}
}

void	print_map(t_d *data)
{
	print_tiles(data);
	print_pos(data);
	mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->map.img_data,
		WIDTH / WIDTH_COEF, HEIGHT / HEIGHT_COEF);
}
