#include "clock_chest.h"

void ft_init_game(s_game *game)
{
	game->window = 0;
	game->hbox = 0;
	ft_init_vbox(game->vbox);
	ft_init_button(game->button);
	game->vbox_victoire = 0;
	game->player = 0;
	game->game = 1;
	game->pause = 0;
	game->player1 = 0;
	game->player2 = 0;
}

void ft_creat_game(s_game *game)
{
	ft_init_game(game);
	game->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(game->window), "ChestClock AKA CC");
	gtk_window_set_default_size(GTK_WINDOW(game->window), 260, 240);
	gtk_window_set_position(GTK_WINDOW(game->window), GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(game->window), "destroy", G_CALLBACK(ft_button_13), (gpointer)game);
	gtk_window_fullscreen(GTK_WINDOW(game->window));
}
