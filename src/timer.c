#include "clock_chest.h"

int	ft_compteur(gpointer data)
{
	s_game	*game;
	gchar	*str;
	
	game = (s_game *)data;
	if (game->game == 1)
	{
		if (!game->pause)
		{
			if (game->player == 1)
			{
				if (game->player1 <= 0)
					remove_timer(game);
				str = ft_time((int)game->player1 / 1);
				gtk_button_set_label(GTK_BUTTON(game->button[15]), str);
				game->player1 = game->player1 - 0.25;
				free(str);
			}
			else if (game->player == 2)
			{
				if (game->player2 <= 0)
					remove_timer(game);
				str = ft_time((int)game->player2 / 1);
				gtk_button_set_label(GTK_BUTTON(game->button[16]), str);
				game->player2 = game->player2 - 0.25;
				free(str);
			}
		}
	}
	return (1);
}

void	ft_creat_timer(s_game *game)
{
	GtkWidget	*label;

	label = 0;
	gtk_container_add(GTK_CONTAINER(game->window), game->vbox_timer);
	gtk_widget_show_all(game->window);
}
