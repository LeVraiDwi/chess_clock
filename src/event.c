#include "clock_chest.h"

void	ft_button_0(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 1;
	game->player2 = game->player1;
	game->tbonus = 0;
	remove_main_menu(game);
	ft_creat_timer(game);
}

void	ft_button_1(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 2;
	game->player2 = game->player1;
	game->tbonus = 1;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_2(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 3;
	game->player2 = game->player1;
	game->tbonus = 0;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_3(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 3;
	game->player2 = game->player1;
	game->tbonus = 2;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_4(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 5;
	game->player2 = game->player1;
	game->tbonus = 0;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_5(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 5;
	game->player2 = game->player1;
	game->tbonus = 3;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_6(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 10;
	game->player2 = game->player1;
	game->tbonus = 0;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_7(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 10;
	game->player2 = game->player1;
	game->tbonus = 5;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_8(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 15;
	game->player2 = game->player1;
	game->tbonus = 10;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_9(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 30;
	game->player2 = game->player1;
	game->tbonus = 0;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_10(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	game->player1 = 30;
	game->player2 = game->player1;
	game->tbonus = 20;
	remove_main_menu(game);
	ft_creat_timer(game);

}

void	ft_button_11(GtkWidget *objet, gpointer data)
{
	s_game	*game;

	game = (s_game*)data;
	remove_main_menu(game);
	ft_creat_timer(game);

}
