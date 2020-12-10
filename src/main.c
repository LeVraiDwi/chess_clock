#include "clock_chest.h"

int	main(int argc, char **argv)
{
	s_game	game;

	gtk_init(&argc, &argv);
	ft_creat_game(&game);
	ft_set_style(&game);
	ft_creat_main_menu(&game);
	g_timeout_add_full(G_PRIORITY_HIGH, 250, ft_compteur, (gpointer)&game, 0);
	gtk_main();
	return 1;
}
