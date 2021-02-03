#include "clock_chest.h"

void	ft_bullet_1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 60;
	game->start2 = 60;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 0;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_bullet_2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 120;
	game->start2 = 120;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 1;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_blitz_1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 180;
	game->start2 = 180;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 0;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_blitz_2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 180;
	game->start2 = 180;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 2;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_blitz_3(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 300;
	game->start2 = 300;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 0;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_blitz_4(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 300;
	game->start2 = 300;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 3;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_rapid_1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 600;
	game->start2 = 600;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 3;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_rapid_2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 600;
	game->start2 = 600;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 5;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_rapid_3(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 900;
	game->start2 = 900;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 10;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_rapid_4(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 1800;
	game->start2 = 1800;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 0;
game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_rapid_5(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[20];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = 1800;
	game->start2 = 1800;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[1] = 20;
	game->tbonus[0] = game->tbonus[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}
