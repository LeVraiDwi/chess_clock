#include "clock_chest.h"

int	ft_timer(gpointer data)
{
	s_game	*game;
	gdouble	player_time;
	char	str[15];

	game = (s_game *)data;
	if (game->pause == 0)
	{
		if (game->player == 1)
		{
			player_time = game->player1 - g_timer_elapsed(game->timer1, 0);
			sprintf(str, "%.2i : %.2i", (int)(player_time / 60), ((int)(player_time / 1)) % 60);
			gtk_button_set_label(GTK_BUTTON(game->button[2]), str);
			if (player_time <= 0)
				return (0);
		}
		else if (game->player == -1)
		{
			player_time = game->player2 - g_timer_elapsed(game->timer2, 0);
			sprintf(str, "%.2i : %.2i", (int)(player_time / 60), ((int)(player_time / 1)) % 60);
			gtk_button_set_label(GTK_BUTTON(game->button[3]), str);
			if (player_time <= 0)
				return (0);
		}
	}
	return (1);
}


void	ft_add_tbonus(gdouble tbonus, GtkWidget *button, GTimer *timer, gdouble player)
{
	char	str[20];
	gdouble	player_time;

	player += tbonus;
	player_time = player - g_timer_elapsed(timer, 0);
	sprintf(str, "%.2i : %.2i", (int)(player_time / 60), ((int)(player_time / 1)) % 60);
	gtk_button_set_label(GTK_BUTTON(button), str);
}

void	ft_creat_timer(s_game *game)
{
	GtkWidget	*label;

	label = 0;
	ft_creat_button(game->button);
	//ft_creat_box_timer(game);
	ft_signal_timer(game);
	ft_creat_menu(game);
	//gtk_container_add(GTK_CONTAINER(game->window), game->vbox_timer);
	gtk_widget_show_all(game->window);
}
