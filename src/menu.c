#include "clock_chest.h"

void	ft_signal_timer(s_game *game)
{
	g_signal_connect(G_OBJECT(game->button[0]), "clicked", G_CALLBACK(ft_button_0), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[1]), "clicked", G_CALLBACK(ft_button_1), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[2]), "clicked", G_CALLBACK(ft_button_2), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[3]), "clicked", G_CALLBACK(ft_button_3), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[4]), "clicked", G_CALLBACK(ft_button_4), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[5]), "clicked", G_CALLBACK(ft_custom), (gpointer)game);
}

void	ft_creat_menu(s_game *game)
{
	game->grid = gtk_grid_new();
	ft_creat_grid_timer(game);
	gtk_container_add(GTK_CONTAINER(game->window), GTK_WIDGET(game->grid));
}

void	ft_creat_custom(s_game *game, GtkWidget *grid)
{
	GtkWidget	*button;
	GtkStyleContext	*context;

	//creation des label
	game->label_custom[0] = gtk_label_new("00");
	context = gtk_widget_get_style_context(game->label_custom[0]);
	gtk_style_context_add_class(context, "mod_label");
	button = 0;
	button = gtk_label_new(":");
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_label");
	gtk_grid_attach(GTK_GRID(grid), game->label_custom[0], 6, 2, 1, 1);
	game->label_custom[1] = gtk_label_new("00");
	context = gtk_widget_get_style_context(game->label_custom[1]);
	gtk_style_context_add_class(context, "mod_label");
	gtk_grid_attach(GTK_GRID(grid), game->label_custom[1], 8, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), button, 7, 2, 1, 1);
	button = 0;
	button = gtk_label_new("temps joueur:");
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_stitre");
	gtk_grid_attach(GTK_GRID(grid), button, 6, 0, 3, 1);
	button = 0;
	button = gtk_label_new("temps bonus:");
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_stitre");
	gtk_grid_attach(GTK_GRID(grid), button, 6, 4, 3, 1);
	button = 0;
	button = gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_plus_min), (gpointer)game);
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_button");
	gtk_grid_attach(GTK_GRID(grid), button, 6, 1, 1, 1);
	button = 0;
	button = gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_minus_min), (gpointer)game);
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_button");
	gtk_grid_attach(GTK_GRID(grid), button, 6, 3, 1, 1);
	button = 0;
	button = gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_plus_second), (gpointer)game);
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_button");
	gtk_grid_attach(GTK_GRID(grid), button, 8, 1, 1, 1);
	button = 0;
	button = gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_minus_second), (gpointer)game);
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_button");
	gtk_grid_attach(GTK_GRID(grid), button, 8, 3, 1, 1);
	button = 0;
	button = gtk_button_new_with_label(" go! ");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_leave_custom), (gpointer)game);
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_go");
	gtk_grid_attach(GTK_GRID(grid), button, 6, 8, 3, 1);
	button = 0;
	game->label_custom[2] = gtk_label_new("00 : 00");
	context = gtk_widget_get_style_context(game->label_custom[2]);
	gtk_style_context_add_class(context, "mod_label");
	gtk_grid_attach(GTK_GRID(grid), game->label_custom[2], 6, 6, 3, 1);
	button = gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_plus_bonus), (gpointer)game);
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_button");
	gtk_grid_attach(GTK_GRID(grid), button, 6, 5, 3, 1);
	button = gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_minus_bonus), (gpointer)game);
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_button");
	gtk_grid_attach(GTK_GRID(grid), button, 6, 7, 3, 1);
	button = 0;
	button = gtk_label_new(" ");
	context = gtk_widget_get_style_context(button);
	gtk_style_context_add_class(context, "mod_ligne");
	gtk_grid_attach(GTK_GRID(grid), button, 5, 0, 1, 10);
	button = 0;
//	button = gtk_label_new(" ");
//	gtk_grid_attach(GTK_GRID(grid), button, 6, 8, 3, 1);
}

void	ft_menu(s_game *game, GtkWidget *grid)
{
	GtkWidget	*menu_item;
	GtkStyleContext	*context;

	menu_item = 0;
	menu_item = gtk_label_new("Mode de jeu: ");
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_titre");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 0, 1, 1);
	//bullet
	menu_item = 0;
	menu_item = gtk_button_new_with_label("1 minute + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_bullet_1), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 1, 1, 1);
	menu_item = 0;
	menu_item = gtk_button_new_with_label("2 minutes + 1 secondes");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_bullet_2), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 2, 1, 1);
	menu_item = 0;
	//blitz
	menu_item = gtk_button_new_with_label("3 minutes + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_blitz_1), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 3, 1, 1);
	menu_item = 0;
	menu_item = gtk_button_new_with_label("3 minutes + 2 secondes");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_blitz_2), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 4, 1, 1);
	menu_item = 0;
	menu_item = gtk_button_new_with_label("5 minutes + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_blitz_3), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 5, 1, 1);
	menu_item = 0;
	menu_item = gtk_button_new_with_label("5 minutes + 3 secondes");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_blitz_4), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 6, 1, 1);
	menu_item = 0;
	//rapid
	menu_item = gtk_button_new_with_label("10 minutes + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_rapid_1), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 7, 1, 1);
	menu_item = 0;
	menu_item = gtk_button_new_with_label("10 minutes + 5 secondes");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_rapid_2), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 0, 8, 1, 1);
	menu_item = 0;
	menu_item = gtk_button_new_with_label("15 minutes + 10 secondes");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_rapid_3), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 1, 1, 1, 1);
	menu_item = 0;
	menu_item = gtk_button_new_with_label("30 minutes + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_rapid_4), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 1, 2, 1, 1);
	menu_item = 0;
	menu_item = gtk_button_new_with_label("30 minutes + 20 secondes");
	g_signal_connect(G_OBJECT(menu_item), "clicked", G_CALLBACK(ft_rapid_5), (gpointer)game);
	context = gtk_widget_get_style_context(menu_item);
	gtk_style_context_add_class(context, "mod_menu");
	gtk_grid_attach(GTK_GRID(grid), menu_item, 1, 3, 1, 1);
}
