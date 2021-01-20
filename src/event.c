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
	context = gtk_widget_get_style_context(game->button[3]);
	gtk_style_context_add_class(context, "timer1_blanc");
	if (game->window_custom == 0)
	{
		gtk_widget_destroy(game->window_custom);
		game->window_custom = 0;
	}
	else if (game->game == 1)
	{
		if (game->pause == 1)
		{
			if (game->player == 1)
				g_timer_continue(game->timer1);
			else
				g_timer_continue(game->timer2);
			gtk_button_set_label(GTK_BUTTON(game->button[1]),"pause");
			game->pause = 0;
		}
		else if (game->pause == 0)
		{
			if (game->player == 1)
				g_timer_stop(game->timer1);
			else
				g_timer_stop(game->timer2);
			gtk_button_set_label(GTK_BUTTON(game->button[1]),"play");
			game->pause = 1;
		}
	}
}

void	ft_button_2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

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
			gtk_button_set_label(GTK_BUTTON(game->button[1]),"play");
			g_timeout_add_full(G_PRIORITY_HIGH, 250, (GSourceFunc)ft_timer, (gpointer)game, 0);
		}
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
			gtk_button_set_label(GTK_BUTTON(game->button[1]),"pause");
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
		if (game->start1 != 0 || game->start2 != 0)
		{
			game->game = 1;
			game->pause = 0;
			game->player = -1;
			game->player1 = game->start1;
			game->player2 = game->start2;
			game->timer2 = g_timer_new();
			gtk_button_set_label(GTK_BUTTON(game->button[1]),"play");
			g_timeout_add_full(G_PRIORITY_HIGH, 250, (GSourceFunc)ft_timer, (gpointer)game, 0);
		}
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
			gtk_button_set_label(GTK_BUTTON(game->button[1]),"pause");
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

void	ft_button_4(GtkWidget *objet, gpointer data)
{
	char	str[15];
	s_game	*game;
	
	if (game->game == 1 || game->timer1 != 0)
	{
		game = (s_game *)data;
		game->game = 0;
		game->pause = 0;
		g_timer_destroy(game->timer1);
		g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
		gtk_button_set_label(GTK_BUTTON(game->button[1]),"play");
		sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->start1) % 60);
		gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
		sprintf(str, "%2.2i : %2.2i", (int)(game->player2 / 60), (int)(game->start2) % 60);
		gtk_button_set_label(GTK_BUTTON(game->button[3]),str);
	}
}

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
	game->tbonus = 0;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 1;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 0;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 2;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 0;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 3;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 3;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 5;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 10;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 0;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
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
	game->tbonus = 20;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
}

void	ft_custom(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game *)data;
	game->time = 0;
	game->timeb = 0;
	if (game->game == 1 && game->pause == 0)
	{
		game->pause = 1;
		if (game->player == 1)
			g_timer_stop(game->timer1);
		else
			g_timer_stop(game->timer2);
	}
	game->window_custom = gtk_window_new(GTK_WINDOW_POPUP);
	gtk_window_set_transient_for(GTK_WINDOW(game->window_custom), GTK_WINDOW(game->window));
	gtk_window_set_position(GTK_WINDOW(game->window_custom), GTK_WIN_POS_CENTER_ON_PARENT);
	ft_creat_custom(game);
	gtk_widget_show_all(game->window_custom);
	gtk_main();
}

void	ft_minus_min(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->time >= 60)
	{
		game->time -= 60;
		sprintf(str, "%2.2i", (int)(game->time / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[0]), str);
	}

}

void	ft_minus_second(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->time > 0)
	{
		game->time -= 1;
		sprintf(str, "%2.2i", (int)(game->time % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[1]), str);
	}

}

void	ft_plus_min(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->time += 60;
	sprintf(str, "%2.2i", (int)(game->time / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[0]), str);
}

void	ft_plus_second(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->time += 1;
	sprintf(str, "%2.2i", (int)(game->time % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[1]), str);
}

void	ft_leave_custom(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->game == 1)
	{
		game->game = 0;
		game->pause = 0;
		if (game->timer1 != 0)
			g_timer_destroy(game->timer1);
		if (game->timer2 != 0)
			g_timer_destroy(game->timer2);
		game->timer1 = 0;
		game->timer2 = 0;
	}
	game->start1 = (gdouble)game->time;
	game->start2 = (gdouble)game->time;
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus = (gdouble)game->timeb;
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}

void	ft_minus_bonus(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->timeb > 0)
	{
		game->timeb -= 1;
		sprintf(str, "%2.2i : %2.2i", (int)(game->timeb / 60), (int)(game->timeb) % 60);
		gtk_label_set_label(GTK_LABEL(game->label_custom[2]), str);
	}

}

void	ft_plus_bonus(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->timeb += 1;
	sprintf(str, "%2.2i : %2.2i", (int)(game->timeb / 60), (int)(game->timeb) % 60);
	gtk_label_set_label(GTK_LABEL(game->label_custom[2]), str);
}
