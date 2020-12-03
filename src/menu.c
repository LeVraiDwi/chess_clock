#include "clock_chest.h"

void ft_creat_main_menu(s_game *game)
{
	GtkWidget	*window;

	window=game->window;
	ft_creat_button(game->button);
	game->hbox = gtk_hbox_new(1, 0);
	ft_creat_vbox(game->vbox);
	ft_affichage_button(game);
	ft_signal_menu(game);
	gtk_widget_show_all(game->window);
}

void	ft_signal_menu(s_game *game)
{
	g_signal_connect(G_OBJECT(game->button[0]), "clicked", G_CALLBACK(ft_button_0), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[1]), "clicked", G_CALLBACK(ft_button_1), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[2]), "clicked", G_CALLBACK(ft_button_2), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[3]), "clicked", G_CALLBACK(ft_button_3), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[4]), "clicked", G_CALLBACK(ft_button_4), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[5]), "clicked", G_CALLBACK(ft_button_5), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[6]), "clicked", G_CALLBACK(ft_button_6), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[7]), "clicked", G_CALLBACK(ft_button_7), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[8]), "clicked", G_CALLBACK(ft_button_8), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[9]), "clicked", G_CALLBACK(ft_button_9), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[10]), "clicked", G_CALLBACK(ft_button_10), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[11]), "clicked", G_CALLBACK(ft_button_11), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[12]), "clicked", G_CALLBACK(gtk_main_quit), NULL);
}
