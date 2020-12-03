#include "clock_chest.h"

void	remove_main_menu(s_game *game)
{
	gtk_container_remove(GTK_CONTAINER(game->window), game->hbox);
}
