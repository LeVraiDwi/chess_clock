#include "clock_chest.h"

int	main(int argc, char **argv)
{
	s_game	game;

	gtk_init(&argc, &argv);
	ft_creat_game(&game);
	ft_creat_main_menu(&game);
//	ft_compteur(&game);
	gtk_main();
	return 1;
}
