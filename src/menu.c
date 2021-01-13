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
	gtk_menu_shell_append(GTK_MENU_SHELL(game->menu_button), menu_item);
}
