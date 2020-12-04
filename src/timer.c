#include "clock_chest.h"

void	ft_compteur(s_game *game)
{
	while (1)
	{
		while (game->game == 1)
		{
			while (game->player == 1 && game->player1 && !game->pause)
			{
				sleep(1);
				game->player1--;
				ft_refresh(game);
			}
			if (!game->pause)
				game->player1 += game->tbonus;
			while (game->player == 2 && game->player2 && !game->pause)
			{
				sleep(1);
				game->player2--;
				ft_refresh(game);
			}
			if (!game->pause)
				game->player2 += game->tbonus;
		}
	}
}

void	ft_creat_timer(s_game *game)
{
	GtkWidget	*label;

	label = 0;
	gtk_container_add(GTK_CONTAINER(game->window), game->vbox_timer);
	gtk_widget_show_all(game->window);
}

void ft_refresh(s_game *game)
{
	char	*str;
	char	*tmp;
	if (game->player == 1)
	{
		str = ft_time(game->player1);

		gtk_button_set_label(GTK_BUTTON(game->button[15]),(gchar *)str);
	}
	else if (game->player == 2)
	{
		gtk_button_set_label(GTK_BUTTON(game->button[16]),(gchar *)str);
	}
}
