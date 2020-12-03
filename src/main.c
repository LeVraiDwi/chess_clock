#include "clock_chest.h"

void	ft_init_button(GtkWidget *button[])
{
	button[0] = 0;
	button[1] = 0;
	button[2] = 0;
	button[3] = 0;
	button[4] = 0;
	button[5] = 0;
	button[6] = 0;
	button[7] = 0;
	button[8] = 0;
	button[9] = 0;
	button[10] = 0;
	button[11] = 0;
	button[12] = 0;
	button[13] = 0;
}

void	ft_creat_button(GtkWidget *button[])
{
	button[0] = gtk_button_new_with_label("Bullet\n1 + 0");
	button[1] = gtk_button_new_with_label("Bullet\n2 + 1");
	button[2] = gtk_button_new_with_label("Blitz\n3 + 0");
	button[3] = gtk_button_new_with_label("Blitz\n3 + 2");
	button[4] = gtk_button_new_with_label("Blitz\n5 + 0");
	button[5] = gtk_button_new_with_label("Blitz\n5 + 3");
	button[6] = gtk_button_new_with_label("Rapid\n10 + 0");
	button[7] = gtk_button_new_with_label("Rapid\n10 + 5");
	button[8] = gtk_button_new_with_label("Rapid\n15 + 10");
	button[9] = gtk_button_new_with_label("Rapid\n30 + 0");
	button[10] = gtk_button_new_with_label("Rapid\n30 + 20");
	button[11] = gtk_button_new_with_label("Custom...");
	button[12] = gtk_button_new_with_label("Leave");
}

void	ft_affichage_button(s_game *game)
{
	gtk_box_pack_start(GTK_BOX(game->vbox[0]), game->button[0], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[0]), game->button[1], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[0]), game->button[12], FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox), game->vbox[0], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[1]), game->button[2], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[1]), game->button[3], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[1]), game->button[4], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[1]), game->button[5], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox), game->vbox[1], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[2]), game->button[6], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[2]), game->button[7], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[2]), game->button[8], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[2]), game->button[9], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[2]), game->button[10], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox), game->vbox[2], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox[3]), game->button[11], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox), game->vbox[3], TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(game->window), game->hbox);
}

void	ft_init_vbox(GtkWidget *vbox[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		vbox[i] = 0;
		i++;
	}
}

void	ft_creat_vbox(GtkWidget *vbox[])
{
	int	i;

	i = 1;
	vbox[0] = gtk_vbox_new(0,0);
	while (i < 4)
	{
		vbox[i] = gtk_vbox_new(1,0);
		i++;
	}
}

void ft_creat_main_menu(s_game *game)
{
	GtkWidget	*window;

	window=game->window;
	ft_creat_button(game->button);
	game->hbox = gtk_hbox_new(1, 0);
	ft_creat_vbox(game->vbox);
	ft_affichage_button(game);
	g_signal_connect(G_OBJECT(game->button[12]), "clicked", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(game->window);
}

void ft_init_game(s_game *game)
{
	game->window = 0;
	game->hbox = 0;
	ft_init_vbox(game->vbox);
	ft_init_button(game->button);
	game->player = 0;
	game->game = 1;
	game->pause = 0;
	game->player1 = 0;
	game->player2 = 0;
}

void ft_creat_game(s_game *game)
{
	game->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(game->window), "ChestClock AKA CC");
	gtk_window_set_default_size(GTK_WINDOW(game->window), 260, 240);
	gtk_window_set_position(GTK_WINDOW(game->window), GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(game->window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_fullscreen(GTK_WINDOW(game->window));
	ft_init_game(game);
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

int	main(int argc, char **argv)
{
	s_game	game;

	gtk_init(&argc, &argv);
	ft_creat_game(&game);
	ft_creat_main_menu(&game);
	gtk_main();
	return 1;
}

