#include "clock_chest.h"


int	main(int argc, char **argv)
{
	s_game	game;
	pthread_t	*thread;

	gtk_init(&argc, &argv);
	ft_init_wiring();
	ft_creat_game(&game);
	ft_set_style(&game);
	ft_creat_timer(&game);
//	g_idle_add((GSourceFunc)ft_read_button, (gpointer)&game);
	gtk_main();
}

