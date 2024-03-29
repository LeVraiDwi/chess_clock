#include "clock_chest.h"

void	remove_main_menu(s_game *game)
{
	game->pause = 1;
	game->game = 1;
	game->player = 0;
	gtk_container_remove(GTK_CONTAINER(game->window), game->hbox);
	gtk_container_add(GTK_CONTAINER(game->window), game->vbox_timer);
	//gtk_button_set_label(GTK_BUTTON(game->button[14]), "cliquer sur le joueur qui commence");
	gtk_widget_show_all(game->window);
}

void	remove_timer(s_game *game)
{
	game->game = 0;
	game->pause = 1;
	game->player = 0;
	gtk_container_remove(GTK_CONTAINER(game->window), game->vbox_timer);
	gtk_container_add(GTK_CONTAINER(game->window), game->hbox);
	gtk_widget_show_all(game->window);
}

void	ft_set_victoire(s_game *game)
{
	game->game = 0;
	game->pause = 1;
	game->player = 0;
	gtk_container_remove(GTK_CONTAINER(game->window), game->vbox_timer);
	if (game->player == 1)
		gtk_label_set_label(GTK_LABEL(game->victoire), "player 2 a gagner");
	if (game->player == 2)
		gtk_label_set_label(GTK_LABEL(game->victoire), "player 1 a gagner");
	gtk_container_add(GTK_CONTAINER(game->window), game->vbox_victoire);
	gtk_widget_show_all(game->window);
}
