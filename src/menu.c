#include "clock_chest.h"

void	ft_signal_timer(s_game *game)
{
	g_signal_connect(G_OBJECT(game->button[0]), "clicked", G_CALLBACK(ft_button_0), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[1]), "clicked", G_CALLBACK(ft_button_1), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[2]), "clicked", G_CALLBACK(ft_button_2), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[3]), "clicked", G_CALLBACK(ft_button_3), (gpointer)game);
	g_signal_connect(G_OBJECT(game->button[4]), "clicked", G_CALLBACK(ft_button_4), (gpointer)game);
}

void	ft_creat_menu(s_game *game)
{
	game->grid = gtk_grid_new();
	ft_menu(game);
	ft_creat_grid_timer(game);
	gtk_container_add(GTK_CONTAINER(game->window), GTK_WIDGET(game->grid));
}

void	ft_creat_custom(s_game *game)
{
	GtkWidget	*button;

	//la grille
	game->grid_custom = gtk_grid_new();
	//ajout de la grille
	gtk_container_add(GTK_CONTAINER(game->window_custom), GTK_WIDGET(game->grid_custom));
	//creation des label
	game->label_custom[0] = gtk_label_new("00");
	button = 0;
	button = gtk_label_new(":");
	gtk_grid_attach(GTK_GRID(game->grid_custom), game->label_custom[0], 1, 3, 3, 1);
	game->label_custom[1] = gtk_label_new("00");
	gtk_grid_attach(GTK_GRID(game->grid_custom), game->label_custom[1], 5, 3, 3, 1);
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 4, 3, 1, 1);
	button = 0;
	button = gtk_label_new("temps joueur:");
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 0, 1, 8, 1);
	button = 0;
	button = gtk_label_new("temps bonus:");
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 0, 5, 8, 1);
	button = 0;
	button = gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_plus_min), (gpointer)game);
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 1, 2, 3, 1);
	button = 0;
	button = gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_minus_min), (gpointer)game);
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 1, 4, 3, 1);
	button = 0;
	button = gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_plus_second), (gpointer)game);
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 5, 2, 3, 1);
	button = 0;
	button = gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_minus_second), (gpointer)game);
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 5, 4, 3, 1);
	button = 0;
	button = gtk_button_new_with_label(" go! ");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_leave_custom), (gpointer)game);
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 0, 9, 9, 1);
	button = 0;
	game->label_custom[2] = gtk_label_new("00 : 00");
	gtk_grid_attach(GTK_GRID(game->grid_custom), game->label_custom[2], 1, 7, 8, 1);
	button = gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_plus_bonus), (gpointer)game);
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 1, 6, 7, 1);
	button = gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(ft_minus_bonus), (gpointer)game);
	gtk_grid_attach(GTK_GRID(game->grid_custom), button, 1, 8, 7, 1);
}

void	ft_menu(s_game *game)
{
	GtkWidget	*submenu;
	GtkWidget	*menu_item;
	GtkWidget	*menu;

	game->menu_button = 0;
	game->menu_button = gtk_menu_bar_new();
	//bullet
	menu = gtk_menu_new();
	menu_item = gtk_menu_item_new_with_label("1 minute + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_bullet_1), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_label("2 minutes + 1 secondes");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_bullet_2), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	//ajout de bullet
	menu_item = gtk_menu_item_new_with_label("Bullet");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(game->menu_button), menu_item);
	//blitz
	menu = gtk_menu_new();
	menu_item = gtk_menu_item_new_with_label("3 minutes + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_blitz_1), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_label("3 minutes + 2 secondes");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_blitz_2), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_label("5 minutes + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_blitz_3), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_label("5 minutes + 3 secondes");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_blitz_4), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	//ajout blitz
	menu_item = gtk_menu_item_new_with_label("Blitz");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(game->menu_button), menu_item);
	//rapid
	menu = gtk_menu_new();
	menu_item = gtk_menu_item_new_with_label("10 minutes + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_rapid_1), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_label("10 minutes + 5 secondes");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_rapid_2), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_label("15 minutes + 10 secondes");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_rapid_3), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_label("30 minutes + 0 seconde");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_rapid_4), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_label("30 minutes + 20 secondes");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_rapid_5), (gpointer)game);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	//ajout rapid
	menu_item = gtk_menu_item_new_with_label("Rapid");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(game->menu_button), menu_item);
	//ajout custome
	menu_item = gtk_menu_item_new_with_label("Custom");
	g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(ft_custom), (gpointer)game);
	game->popover = gtk_popover_new(menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(game->menu_button), menu_item);
}
