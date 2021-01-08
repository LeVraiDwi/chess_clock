#include "clock_chest.h"

void	ft_button_0(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	
	g_object_unref(game->vbox_timer);
	gtk_main_quit();
}

void	ft_button_1(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game *)data;
	if (game->player != 0)
		game->pause = !game->pause;
	else if (game->pause == 0)
		gtk_button_set_label(GTK_BUTTON(game->button[0]),"pause");
	else if (game->pause == 1)
		gtk_button_set_label(GTK_BUTTON(game->button[0]),"play");
	
}

void	ft_button_2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->game == 0)
	{
		game->game = 1;
		game->pause = 0;
		game->player = 1;
		game->timer1 = g_timer_new();
		gtk_button_set_label(GTK_BUTTON(game->button[1]),"pause");
		sprintf(str, "%2.2i : %02.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
		gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
		sprintf(str, "%2.2i : %02.2i", (int)(game->player2 / 60), (int)(game->player2) % 60);
		gtk_button_set_label(GTK_BUTTON(game->button[3]),str);
		g_timeout_add_full(G_PRIORITY_HIGH, 250, (GSourceFunc)ft_timer, (gpointer)game, 0);
	}
	else if (game->game == 1)
	{
		if (game->pause == 0)
		{
			if (game->player == 1)
			{
				g_timer_stop(game->timer1);
				ft_add_tbonus(game->tbonus, game->button[2], game->timer1, game->player1);
				if (game->timer2 == 0)
					game->timer2 = g_timer_new();
				else
					g_timer_continue(game->timer2);
				
			}
			else if (game->player == -1)
			{
				g_timer_stop(game->timer2);
				ft_add_tbonus(game->tbonus, game->button[3], game->timer2, game->player2);
				if (game->timer1 == 0)
					game->timer1 = g_timer_new();
				else
					g_timer_continue(game->timer1);
			}
			game->player = game->player * -1;
		}
		else if (game->pause == 1 && game->game == 1)
		{
			game->pause = 0;
			if (game->player == 1)
			{
				if (game->timer1 == 0)
					game->timer1 = g_timer_new();
				else
					g_timer_continue(game->timer1);
			}
			else
			{
				if (game->timer2 == 0)
					game->timer2 = g_timer_new();
				else
					g_timer_continue(game->timer2);
			}
		}
	}
}

void	ft_button_3(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->game == 0)
	{
		game->game = 1;
		game->pause = 0;
		game->player = -1;
		game->timer1 = g_timer_new();
		gtk_button_set_label(GTK_BUTTON(game->button[1]),"pause");
		sprintf(str, "%2.i : %2.i", (int)(game->player1 / 60), (int)(game->player1) % 60);
		gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
		sprintf(str, "%2.i : %2.i", (int)(game->player2 / 60), (int)(game->player2) % 60);
		gtk_button_set_label(GTK_BUTTON(game->button[3]),str);
		g_timeout_add_full(G_PRIORITY_HIGH, 250, (GSourceFunc)ft_timer, (gpointer)game, 0);
	}
	else if (game->game == 1)
	{
		if (game->pause == 0)
		{
			if (game->player == 1)
			{
				g_timer_stop(game->timer1);
				ft_add_tbonus(game->tbonus, game->button[2], game->timer1, game->player1);
				if (game->timer2 == 0)
					game->timer2 = g_timer_new();
				else
					g_timer_continue(game->timer2);
			}
			else if (game->player == -1)
			{
				g_timer_stop(game->timer2);
				ft_add_tbonus(game->tbonus, game->button[3], game->timer2, game->player2);
				if (game->timer1 == 0)
					game->timer1 = g_timer_new();
				else
					g_timer_continue(game->timer1);
			}
			game->player = game->player * -1;
		}
		else if (game->pause == 1 && game->game == 1)
		{
			game->pause = 0;
			if (game->player == 1)
			{
				if (game->timer1 == 0)
					game->timer1 = g_timer_new();
				else
					g_timer_continue(game->timer1);
			}
			else
			{
				if (game->timer2 == 0)
					game->timer2 = g_timer_new();
				else
					g_timer_continue(game->timer2);
			}
		}
	}
}
