#include "clock_chest.h"

void	ft_signal_timer(s_game *game)
{
	g_signal_connect(G_OBJECT(game->button[0]), "clicked", G_CALLBACK(ft_button_0), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[1]), "clicked", G_CALLBACK(ft_button_1), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[2]), "clicked", G_CALLBACK(ft_button_2), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[3]), "clicked", G_CALLBACK(ft_button_3), (gpointer)game);
}

void	ft_creat_menu(s_game *game)
{
	game->grid = gtk_grid_new();
	ft_creat_grid_timer(game);
	gtk_container_add(GTK_CONTAINER(game->window), GTK_WIDGET(game->grid));
}
