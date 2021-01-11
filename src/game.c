#include "clock_chest.h"

void ft_init_game(s_game *game)
{
	game->window = 0;
	ft_init_button(game->button);
	ft_init_box(game);
	game->vbox_timer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	ft_creat_hbox(game->hbox_timer);
	game->player = 0;
	game->game = 0;
	game->pause = 0;
	game->start1 = 120;
	game->start2 = 120;
	game->tbonus = 1;
	game->timer1 = 0;
	game->timer2 = 0;
}

void ft_creat_game(s_game *game)
{
	ft_init_game(game);
	game->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(game->window), "ChestClock AKA CC");
	gtk_window_set_default_size(GTK_WINDOW(game->window), 260, 240);
	gtk_window_set_position(GTK_WINDOW(game->window), GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(game->window), "destroy", G_CALLBACK(ft_button_0), (gpointer)game);
	gtk_window_fullscreen(GTK_WINDOW(game->window));
}
