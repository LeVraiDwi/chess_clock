#include "clock_chest.h"

void	ft_init_button(GtkWidget *button[])
{
	button[0] = 0;
	button[1] = 0;
	button[2] = 0;
	button[3] = 0;
	button[4] = 0;
	button[5] = 0;
}

void	ft_creat_button(GtkWidget *button[])
{
	GtkStyleContext	*context;

	button[0] = gtk_button_new();
	context = gtk_widget_get_style_context(button[0]);
	gtk_style_context_add_class(context, "leave");
	button[1] = gtk_button_new();
	context = gtk_widget_get_style_context(button[1]);
	gtk_style_context_add_class(context, "play");
	button[2] = gtk_button_new_with_label("00 : 00");
	context = gtk_widget_get_style_context(button[2]);
	gtk_style_context_add_class(context, "timer_b");
	button[3] = gtk_button_new_with_label("00 : 00");
	context = gtk_widget_get_style_context(button[3]);
	gtk_style_context_add_class(context, "timer_n");
	button[4] = gtk_button_new();
	context = gtk_widget_get_style_context(button[4]);
	gtk_style_context_add_class(context, "reset");
	button[5] = gtk_button_new();
	context = gtk_widget_get_style_context(button[5]);
	gtk_style_context_add_class(context, "mod");
}

void	ft_creat_grid_timer(s_game *game)
{
	gtk_grid_set_row_homogeneous(GTK_GRID(game->grid), 1);
	gtk_grid_set_column_homogeneous(GTK_GRID(game->grid), 1);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[0], 10, 0, 1, 5);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[1], 10, 5, 1, 5);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[4], 10, 10, 1, 5);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[5], 10, 15, 1, 5);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[2], 0, 0, 10, 20);
	gtk_grid_attach(GTK_GRID(game->grid), game->button[3], 11, 0, 10, 20);
}
