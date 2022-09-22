int main()
{
	void *mlx = mlx_init();
	void *mlx_win = mlx_new_window(mlx, 1920, 1080, "test");
	t_img img;
	int x;
	int y;
	img.img_data = mlx_new_image(mlx, 1920, 1030);
	img.addr = mlx_get_data_addr(img.img_data,
								 &img.bits_per_pixel, &img.line_length, &img.endian);
	img.img_data = mlx_xpm_file_to_image(mlx, "textures/dark_wall.xpm", &x, &y);
	mlx_put_image_to_window(mlx, mlx_win, img.img_data, 0, 0);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_mlx mlx;
	(void)ac;
	(void)av;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "lol");
	int x; int y;
	mlx.img.img_data = (mlx_xpm_file_to_image(mlx.ptr, "textures/white_wall.xpm", &x, &y));
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_data, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	char	*pxl;
	pxl = mlx.img.addr + (30 * mlx.img.line_length + 960 * (mlx.img.bits_per_pixel / 8));
	*(int *)pxl = PXL;
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img_data, 0, 0);
	mlx_loop(mlx.ptr);
}

int	main(int ac, char **av)
{
	t_p		params;
	char	**tab;
	
	if (args_error(ac, av) == ERROR)
		exit_and_print(ARGS);
	params_init(&params);
	tab = NULL;
	tab = parsing(av[1], &params, tab);
	t_mlx mlx;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "yo\n");
	mlx.img.img_data = mlx_new_image(mlx.ptr, WIDTH / 6, HEIGHT / 6);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_data, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	for (int i = 0; i < WIDTH / 6; i++)
		for (int j = 0; j < HEIGHT / 6; j++)
			ft_pixel_put(&mlx.img, i, j, PXL);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img_data, WIDTH / 50 , HEIGHT / 30);
	mlx_loop(mlx.ptr);
	return (0);
}

		printf("%f perc x\n", map.perc_x);
						printf("%f perc y\n", map.perc_y);
						printf("%d map x\n", map.x);
						printf("%d map y\n", map.y);
						printf("%d wall_size\n", map.wall_size);
						printf("%d pxl_x\n", map.pxl_x);
						printf("%d pxl_y\n", map.pxl_y);
						printf("%d tab_x\n", map.tab_x);
						printf("%d tab_y\n", map.tab_y);
						printf("%d curr wall x\n", map.curr_wall_x);
						printf("%d curr wall y\n", map.curr_wall_y);
