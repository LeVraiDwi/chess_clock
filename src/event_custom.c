#include "clock_chest.h"

void	ft_custom(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	GtkWidget *grid;
	GtkStyleContext	*context;
	GdkRectangle	workarea = {0};
	
	game = (s_game *)data;
	if (game->window_custom == 0)
	{
		game->time = 0;
		game->timeb = 0;
		if (game->game == 1 && game->pause == 0)
		{
			context = gtk_widget_get_style_context(game->button[1]);
			gtk_style_context_remove_class(context, "pause");
			gtk_style_context_add_class(context, "play");
			game->pause = 1;
			if (game->player == 1)
				g_timer_stop(game->timer1);
			else
				g_timer_stop(game->timer2);
		}
		grid = 0;
		grid = gtk_grid_new();
		gtk_grid_set_row_homogeneous(GTK_GRID(grid), 1);
	//	gtk_grid_set_column_homogeneous(GTK_GRID(grid), 1);
		game->window_custom = gtk_window_new(GTK_WINDOW_POPUP);
		gdk_monitor_get_workarea(gdk_display_get_primary_monitor(gdk_display_get_default()), &workarea);
	//	gtk_window_set_default_size(GTK_WINDOW(game->window_custom), workarea.width * 0.8, workarea.height * 0.8);
		gtk_window_set_transient_for(GTK_WINDOW(game->window_custom), GTK_WINDOW(game->window));
		gtk_window_set_position(GTK_WINDOW(game->window_custom), GTK_WIN_POS_CENTER_ON_PARENT);
		gtk_container_add(GTK_CONTAINER(game->window_custom), GTK_WIDGET(grid));
		gtk_grid_set_column_spacing(GTK_GRID(grid), 4);
		ft_menu(game, grid);
		ft_creat_custom(game, grid);
		gtk_widget_show_all(game->window_custom);
		gtk_main();
	}
}

//bouton custom j1
void	ft_minus_min_j1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->time[0] >= 60)
	{
		game->time[0] -= 60;
		sprintf(str, "%2.2i", (int)(game->time[0] / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[0]), str);
		sprintf(str, "%2.2i", (int)(game->time[0] % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[1]), str);
	}

}

void	ft_minus_second_j1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->time[0] > 0)
	{
		game->time[0] -= 1;
		sprintf(str, "%2.2i", (int)(game->time[0] / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[0]), str);
		sprintf(str, "%2.2i", (int)(game->time[0] % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[1]), str);
	}

}

void	ft_plus_min_j1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->time[0] += 60;
	sprintf(str, "%2.2i", (int)(game->time[0] / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[0]), str);
	sprintf(str, "%2.2i", (int)(game->time[0] % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[1]), str);
}

void	ft_plus_second_j1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->time[0] += 1;
	sprintf(str, "%2.2i", (int)(game->time[0] / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[0]), str);
	sprintf(str, "%2.2i", (int)(game->time[0] % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[1]), str);
}

//bouton custom j2
void	ft_minus_min_j2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->time[1] >= 60)
	{
		game->time[1] -= 60;
		sprintf(str, "%2.2i", (int)(game->time[1] / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[2]), str);
		sprintf(str, "%2.2i", (int)(game->time[1] % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[3]), str);
	}

}

void	ft_minus_second_j2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->time[1] > 0)
	{
		game->time[1] -= 1;
		sprintf(str, "%2.2i", (int)(game->time[1] / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[2]), str);
		sprintf(str, "%2.2i", (int)(game->time[1] % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[3]), str);
	}

}

void	ft_plus_min_j2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->time[1] += 60;
	sprintf(str, "%2.2i", (int)(game->time[1] / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[2]), str);
	sprintf(str, "%2.2i", (int)(game->time[1] % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[3]), str);
}

void	ft_plus_second_j2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->time[1] += 1;
	sprintf(str, "%2.2i", (int)(game->time[1] / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[2]), str);
	sprintf(str, "%2.2i", (int)(game->time[1] % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[3]), str);
}

//bouton custom j1 bonus
void	ft_minus_min_b1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->timeb[0] >= 60)
	{
		game->timeb[0] -= 60;
		sprintf(str, "%2.2i", (int)(game->timeb[0] / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[4]), str);
		sprintf(str, "%2.2i", (int)(game->timeb[0] % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[5]), str);
	}

}

void	ft_minus_second_b1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->timeb[0] > 0)
	{
		game->timeb[0] -= 1;
		sprintf(str, "%2.2i", (int)(game->timeb[0] / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[4]), str);
		sprintf(str, "%2.2i", (int)(game->timeb[0] % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[5]), str);
	}

}

void	ft_plus_min_b1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->timeb[0] += 60;
	sprintf(str, "%2.2i", (int)(game->timeb[0] / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[4]), str);
	sprintf(str, "%2.2i", (int)(game->timeb[0] % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[5]), str);
}

void	ft_plus_second_b1(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->timeb[0] += 1;
	sprintf(str, "%2.2i", (int)(game->timeb[0] / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[4]), str);
	sprintf(str, "%2.2i", (int)(game->timeb[0] % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[5]), str);
}

//bouton custom j2 bonus
void	ft_minus_min_b2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->timeb[1] >= 60)
	{
		game->timeb[1] -= 60;
		sprintf(str, "%2.2i", (int)(game->timeb[1] / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[6]), str);
		sprintf(str, "%2.2i", (int)(game->timeb[1] % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[7]), str);
	}

}

void	ft_minus_second_b2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	if (game->timeb[1] > 0)
	{
		game->timeb[1] -= 1;
		sprintf(str, "%2.2i", (int)(game->timeb[1] / 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[6]), str);
		sprintf(str, "%2.2i", (int)(game->timeb[1] % 60));
		gtk_label_set_label(GTK_LABEL(game->label_custom[7]), str);
	}

}

void	ft_plus_min_b2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->timeb[1] += 60;
	sprintf(str, "%2.2i", (int)(game->timeb[1] / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[6]), str);
	sprintf(str, "%2.2i", (int)(game->timeb[1] % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[7]), str);
}

void	ft_plus_second_b2(GtkWidget *objet, gpointer data)
{
	s_game	*game;
	char	str[15];

	game = (s_game *)data;
	game->timeb[1] += 1;
	sprintf(str, "%2.2i", (int)(game->timeb[1] / 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[6]), str);
	sprintf(str, "%2.2i", (int)(game->timeb[1] % 60));
	gtk_label_set_label(GTK_LABEL(game->label_custom[7]), str);
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
	game->start1 = (gdouble)game->time[0];
	game->start2 = (gdouble)game->time[1];
	game->player1 = game->start1;
	game->player2 = game->start2;
	game->tbonus[0] = (gdouble)game->timeb[0];
	game->tbonus[1] = (gdouble)game->timeb[1];
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
	sprintf(str, "%2.2i : %2.2i", (int)(game->player1 / 60), (int)(game->player1) % 60);
	gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
	gtk_widget_destroy(game->window_custom);
	game->window_custom = 0;
}
