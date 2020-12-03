#ifndef CLOCK_CHEST_H
#	define	CLOCK_CHEST_H
#	include	<time.h>
#	include	<gtk/gtk.h>
#	include <stdlib.h>

typedef struct	t_game
{
	GtkWidget	*window;
	GtkWidget	*hbox;
	GtkWidget	*vbox[4];
	GtkWidget	*button[14];
	unsigned int	player;
	unsigned int	game;
	unsigned int	pause;
	long		player1;
	long		player2;
	long		tbonus;
}		s_game;

void	ft_timer(long j1sec, long j2sec);
void	ft_init_vbox(GtkWidget *vbox[]);
void	ft_creat_vbox(GtkWidget *vbox[]);
void	ft_init_button(GtkWidget *button[]);
void	ft_creat_button(GtkWidget *button[]);
void	ft_affichage_button(s_game *game);
void	ft_init_game(s_game *game);
void	ft_creat_game(s_game *game);
void	ft_creat_main_menu(s_game *game);
void	remove_main_menu(s_game *game);
void	ft_button_0(GtkWidget *objet, gpointer data);
void	ft_button_1(GtkWidget *objet, gpointer data);
void	ft_button_2(GtkWidget *objet, gpointer data);
void	ft_button_3(GtkWidget *objet, gpointer data);
void	ft_button_4(GtkWidget *objet, gpointer data);
void	ft_button_5(GtkWidget *objet, gpointer data);
void	ft_button_6(GtkWidget *objet, gpointer data);
void	ft_button_7(GtkWidget *objet, gpointer data);
void	ft_button_8(GtkWidget *objet, gpointer data);
void	ft_button_9(GtkWidget *objet, gpointer data);
void	ft_button_10(GtkWidget *objet, gpointer data);
void	ft_button_11(GtkWidget *objet, gpointer data);
void	ft_button_12(GtkWidget *objet, gpointer data);
void	ft_signal_menu(s_game *game);
void	ft_creat_timer(s_game *game);
#endif
