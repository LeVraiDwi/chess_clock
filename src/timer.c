#include "clock_chest.h"

void	ft_timer(long j1sec, long j2sec)
{
	int	start;
	
	start = 1;
	while (j1sec != 0 && j2sec != 0 && start)
	{
		while (start == 1 && j1sec)
		{
			printf("j1 seconde : %li\n", j1sec);
			sleep(1);
			j1sec--;
		}
		while (start == 2 && j2sec)
		{
			sleep(1000);
			j2sec--;
		}
	}
}

int	ft_compteur(int temps, int tbonus, s_game *game)
{
	game->player1 = temps;
	game->player2 = temps;
	while (game->game == 1)
	{
		while (game->player == 1 && game->player1 && !game->pause)
		{
			sleep(1);
			game->player1--;
		}
		if (!game->pause)
			game->player1 += tbonus;
		while (game->player == 2 && game->player2 && !game->pause)
		{
			sleep(1);
			game->player2--;
		}
		if (!game->pause)
			game->player2 += tbonus;
	}
}

void	ft_creat_timer(s_game *game)
{
	GtkWidget	*label;

	label = 0;
	label = gtk_label_new("just the two of us");
	gtk_container_add(GTK_CONTAINER(game->window), label);
	gtk_widget_show_all(game->window);
}
