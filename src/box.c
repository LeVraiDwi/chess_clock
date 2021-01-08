#include "clock_chest.h"

void	ft_init_box(s_game *game)
{
	int	i;
	
	game->hbox_timer[0] = 0;
	game->hbox_timer[1] = 0;
	game->vbox_timer = 0;
}

void	ft_creat_hbox(GtkWidget *hbox[])
{
	hbox[0] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	hbox[1] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_set_homogeneous(GTK_BOX(hbox[1]), 1);
}
