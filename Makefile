int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_message(ERR_ARG);
	file_extension(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		error_message(ERR_MEM);
	fill_game(game);
	read_map(game, argv[1]);
	map_control(game);
	flood_fill_controller(game);
	window(game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
}