#include "clock_chest.h"

void ft_creat_main_menu(s_game *game)
{
	GtkWidget	*window;

	window=game->window;
	ft_creat_button(game->button);
	game->hbox = gtk_hbox_new(1, 0);
	ft_creat_vbox(game->vbox);
	ft_affichage_button(game);
	g_signal_connect(G_OBJECT(game->button[12]), "clicked", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(game->window);
}