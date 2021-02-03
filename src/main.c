#include "clock_chest.h"

void	redraw_timer(gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	sprintf(str, "%.2i : %.2i", (int)game->player1 / 60, (int)game->player1 % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%.2i : %.2i", (int)game->player2 / 60, (int)game->player2 % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
}

int	main(int argc, char **argv)
{
	s_game	game;
	pthread_t	*thread;

	gtk_init(&argc, &argv);
	ft_init_wiring();
	ft_creat_game(&game);
	ft_set_style(&game);
	ft_creat_timer(&game);
	g_idle_add((GSourceFunc)ft_read_button, (gpointer)&game);
	gtk_main();
}

