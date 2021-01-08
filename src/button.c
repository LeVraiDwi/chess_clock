#include "clock_chest.h"

void	ft_init_button(GtkWidget *button[])
{
	button[0] = 0;
	button[1] = 0;
	button[2] = 0;
	button[3] = 0;
}

void	ft_creat_button(GtkWidget *button[])
{
	GtkStyleContext	*context;

	button[0] = gtk_button_new_with_label("Leave");
	context = gtk_widget_get_style_context(button[0]);
	gtk_style_context_add_class(context, "leave");
	button[1] = gtk_button_new_with_label("pause/play");
	context = gtk_widget_get_style_context(button[1]);
	gtk_style_context_add_class(context, "play");
	button[2] = gtk_button_new_with_label("timer1");
	context = gtk_widget_get_style_context(button[2]);
	gtk_style_context_add_class(context, "timer1");
	button[3] = gtk_button_new_with_label("timer2");
	context = gtk_widget_get_style_context(button[3]);
	gtk_style_context_add_class(context, "timer2");
	button[4] = gtk_button_new_with_label("reset");
	gtk_style_context_add_class(context, "reset");
}

void	ft_creat_box_timer(s_game *game)
{
	gtk_box_pack_start(GTK_BOX(game->hbox_timer[0]), game->button[2], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox_timer[0]), game->button[3], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox_timer), game->hbox_timer[0], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox_timer[1]), game->button[1], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox_timer[1]), game->button[0], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox_timer), game->hbox_timer[1], FALSE, TRUE, 0);
	g_object_ref((gpointer *)game->vbox_timer);
}

void	ft_creat_grid_timer(s_game *game)
{
	//gtk_grid_attach(GTK_GRID(game->grid), game->button[0], 1, 1, 1, 1);
	gtk_grid_set_row_homogeneous(GTK_GRID(game->grid), 1);
	gtk_grid_set_column_homogeneous(GTK_GRID(game->grid), 1);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[2], 1, 1, 1, 19);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[3], 2, 1, 1, 19);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[1], 1, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[4], 2, 20, 1, 1);
}
