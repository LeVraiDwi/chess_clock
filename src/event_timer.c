#include "clock_chest.h"

void	ft_button_0(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	
	gtk_main_quit();
}

void	ft_button_1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	GtkStyleContext	*context;

	game = (s_game *)data;
	if (game->game == 1)
	{
		if (game->pause == 1)
		{
			if (game->player == 1)
				g_timer_continue(game->timer1);
			else
				g_timer_continue(game->timer2);
			context = gtk_widget_get_style_context(game->button[1]);
			gtk_style_context_remove_class(context, "play");
			gtk_style_context_add_class(context, "pause");
			game->pause = 0;
		}
		else if (game->pause == 0)
		{
			if (game->player == 1)
				g_timer_stop(game->timer1);
			else
				g_timer_stop(game->timer2);
			context = gtk_widget_get_style_context(game->button[1]);
			gtk_style_context_remove_class(context, "pause");
			gtk_style_context_add_class(context, "play");
			game->pause = 1;
		}
	}
}

void	ft_button_2(GtkWidget *objet, gpointer data)
{
	s_game		*game;
	char		str[15];
	GtkStyleContext	*context;

	game = (s_game *)data;
	if (game->game == 0)
	{
		if (game->start1 != 0 && game->start2 != 0)
		{
			game->game = 1;
			game->pause = 0;
			game->player = 1;
			game->player1 = game->start1;
			game->player2 = game->start2;
			game->timer1 = g_timer_new();
			context = gtk_widget_get_style_context(game->button[1]);
			gtk_style_context_remove_class(context, "play");
			gtk_style_context_add_class(context, "pause");
			g_timeout_add_full(G_PRIORITY_HIGH, 100, (GSourceFunc)ft_timer, (gpointer)game, 0);
		}
	}
	else if (game->game == 1)
	{
		if (game->pause == 0)
		{
			if (game->player == 1)
			{
				g_timer_stop(game->timer1);
				ft_add_tbonus(game->tbonus[0], game->button[2], game->timer1, game->player1);
				if (game->timer2 == 0)
					game->timer2 = g_timer_new();
				else
					g_timer_continue(game->timer2);
				
			}
			else if (game->player == -1)
			{
				g_timer_stop(game->timer2);
				ft_add_tbonus(game->tbonus[1], game->button[3], game->timer2, game->player2);
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
			context = gtk_widget_get_style_context(game->button[1]);
			gtk_style_context_remove_class(context, "play");
			gtk_style_context_add_class(context, "pause");
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
	GtkStyleContext	*context;

	game = (s_game *)data;
	if (game->game == 1)
	{
		if (game->pause == 0)
		{
			if (game->player == 1)
			{
				g_timer_stop(game->timer1);
				ft_add_tbonus(game->tbonus[0], game->button[2], game->timer1, game->player1);
				if (game->timer2 == 0)
					game->timer2 = g_timer_new();
				else
					g_timer_continue(game->timer2);
			}
			else if (game->player == -1)
			{
				g_timer_stop(game->timer2);
				ft_add_tbonus(game->tbonus[1], game->button[3], game->timer2, game->player2);
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
			context = gtk_widget_get_style_context(game->button[1]);
			gtk_style_context_remove_class(context, "play");
			gtk_style_context_add_class(context, "pause");
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
	else if (game->game == 0)
	{
		if (game->start1 != 0 || game->start2 != 0)
		{
			game->game = 1;
			game->pause = 0;
			game->player = -1;
			game->player1 = game->start1;
			game->player2 = game->start2;
			game->timer2 = g_timer_new();
			context = gtk_widget_get_style_context(game->button[1]);
			gtk_style_context_remove_class(context, "play");
			gtk_style_context_add_class(context, "pause");
			g_timeout_add_full(G_PRIORITY_HIGH, 100, (GSourceFunc)ft_timer, (gpointer)game, 0);
		}
	}
}

void	ft_button_4(GtkWidget *objet, gpointer data)
{
	char	str[15];
	s_game	*game;
	GtkStyleContext	*context;
	
	game = (s_game *)data;
	context = gtk_widget_get_style_context(game->button[1]);
	gtk_style_context_remove_class(context, "pause");
	gtk_style_context_add_class(context, "play");
	if (game->game == 1 || game->timer1 != 0)
	{
		game->game = 0;
		game->pause = 0;
		if (game->timer1 != 0)
			g_timer_destroy(game->timer1);
		if (game->timer2 != 0)
			g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
		sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->start1) % 60);
		gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
		sprintf(str, "%2.2i : %2.2i", (int)(game->player2 / 60), (int)(game->start2) % 60);
		gtk_button_set_label(GTK_BUTTON(game->button[3]),str);
	}
}



