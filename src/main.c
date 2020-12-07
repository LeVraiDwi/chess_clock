#include "clock_chest.h"

int	main(int argc, char **argv)
{
	s_game	game;

	gtk_init(&argc, &argv);
	ft_creat_game(&game);
	ft_creat_main_menu(&game);
	g_timeout_add_seconds(1, ft_compteur, (gpointer)&game);
	gtk_main();
	return 1;
}
