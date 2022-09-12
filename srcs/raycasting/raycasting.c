/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:43:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/12 23:08:23 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}

void	ft_pixel_put(t_win *img, int x, int y, int color)
{
	char	*pxl;

	if (((x < 1920) && (x >= 0) && (y < 1080) && (y >= 0)))
	{
		pxl = img->addr + (y * img->line_length
				+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

void	raycasting_loop(t_mlx *mlx)
{
	mlx->img.img_data = mlx_new_image(mlx->ptr, 1920, 1030);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_data, &mlx->img.bits_per_pixel,
					&mlx->img.line_length, &mlx->img.endian);
	ft_pixel_put(&mlx->img, 1900, 80, 0x0055FFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_data, 0, 0);
	// mlx_destroy_image(mlx->ptr, mlx->img.img_data);
	// mlx_clear_window(mlx->ptr, mlx->win);
	mlx_loop(mlx->ptr);
}

void	raycasting(char **tab, t_p params)
{
	t_mlx	mlx;
	
	(void)tab;
	(void)params;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "CUB3D");
	mlx_key_hook(mlx.win, key, (void *)0);
	raycasting_loop(&mlx);
}