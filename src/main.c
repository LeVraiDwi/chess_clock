#include "clock_chest.h"

int	main(int argc, char **argv)
{
	s_game	game;

	gtk_init(&argc, &argv);
	ft_creat_game(&game);
	ft_set_style(&game);
	ft_creat_timer(&game);
	gtk_main();
	return 1;
}
