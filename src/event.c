#include "clock_chest.h"

void	ft_button_0(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 1 * 60;
	game->player2 = game->player1;
	game->tbonus = 0;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 2 * 60;
	game->player2 = game->player1;
	game->tbonus = 1;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 3 * 60;
	game->player2 = game->player1;
	game->tbonus = 0;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_3(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 3 * 60;
	game->player2 = game->player1;
	game->tbonus = 2;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_4(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 5 * 60;
	game->player2 = game->player1;
	game->tbonus = 0;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_5(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 5 * 60;
	game->player2 = game->player1;
	game->tbonus = 3;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_6(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 10 * 60;
	game->player2 = game->player1;
	game->tbonus = 0;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_7(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 10 * 60;
	game->player2 = game->player1;
	game->tbonus = 5;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_8(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 15 * 60;
	game->player2 = game->player1;
	game->tbonus = 10;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_9(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 30 * 60;
	game->player2 = game->player1;
	game->tbonus = 0;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_10(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	gchar	*str;

	game = (s_game*)data;
	game->player1 = 30 * 60;
	game->player2 = game->player1;
	game->tbonus = 20;
	str = ft_time(game->player1);
	gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
	free(str);
	str = ft_time(game->player2);
	gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
	free(str);
	remove_main_menu(game);
}

void	ft_button_11(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	remove_main_menu(game);
}

void	ft_button_12(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	
	g_object_unref(game->hbox);
	g_object_unref(game->vbox_timer);
	gtk_main_quit();
}

void	ft_button_13(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game *)data;
	game->game = 0;
	remove_timer(game);
}

void	ft_button_14(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game *)data;
	if (game->player != 0)
		game->pause = !game->pause;
	else if (game->pause == 0)
		gtk_button_set_label(GTK_BUTTON(game->button[14]),"pause");
	else if (game->pause == 1)
		gtk_button_set_label(GTK_BUTTON(game->button[14]),"play");
	
}

void	ft_button_15(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game *)data;
	if (game->pause == 1)
	{
		gtk_button_set_label(GTK_BUTTON(game->button[14]),"pause");
		if (game->player == 0)
			game->player = 1;
	}
	else
	{
		if (game->player == 1)
		{	
			game->player = 2;
			game->player1 += game->tbonus;
			gtk_button_set_label(GTK_BUTTON(game->button[15]), ft_time(game->player1));
		}
		else if (game->player == 2)
		{
			game->player = 1;
			game->player2 += game->tbonus;
			gtk_button_set_label(GTK_BUTTON(game->button[16]), ft_time(game->player2));
		}
	}
	game->game = 1;
	game->pause = 0;
}

void	ft_button_16(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game *)data;
	if (game->pause == 1)
	{
		gtk_button_set_label(GTK_BUTTON(game->button[14]),"pause");
		if (game->player == 0)
			game->player = 2;
	}
	else
	{
		if (game->player == 1)
		{	
			game->player = 2;
			game->player1 += game->tbonus;
			gtk_button_set_label(GTK_BUTTON(game->button[15]), ft_time(game->player1));
		}
		else if (game->player == 2)
		{
			game->player = 1;
			game->player2 += game->tbonus;
			gtk_button_set_label(GTK_BUTTON(game->button[16]), ft_time(game->player2));
		}
	}
	game->game = 1;
	game->pause = 0;
}
