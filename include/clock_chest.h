#ifndef CLOCK_CHEST_H
#	define	CLOCK_CHEST_H
#	include	<time.h>
#	include	<gtk/gtk.h>
#	include <stdlib.h>

typedef	struct	t_style
{
	GtkCssProvider	*provider;
	GdkDisplay	*display;
	GdkScreen	*screen;
}		s_style;

typedef struct	t_game
{
	GtkWidget	*window;
	GtkWidget	*hbox;
	GtkWidget	*hbox_timer[2];
	GtkWidget	*vbox_timer;
	GtkWidget	*vbox[6];
	GtkWidget	*button[18];
	GtkWidget	*menu;
	GtkWidget	*timer;
	GtkWidget	*vbox_victoire;
	GtkWidget	*victoire;
	unsigned int	player;
	unsigned int	game;
	unsigned int	pause;
	float		player1;
	float		player2;
	long		tbonus;
	s_style		style;
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
void	remove_timer(s_game *game);
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
void	ft_button_13(GtkWidget *objet, gpointer data);
void	ft_button_14(GtkWidget *objet, gpointer data);
void	ft_button_15(GtkWidget *objet, gpointer data);
void	ft_button_16(GtkWidget *objet, gpointer data);
void	ft_signal_menu(s_game *game);
void	ft_signal_timer(s_game *game);
void	ft_creat_timer(s_game *game);
void	ft_creat_hbox(GtkWidget *hbox[]);
void	ft_creat_box_timer(s_game *game);
void	ft_refresh(s_game *game);
void	ft_set_style(s_game *game);
void	ft_init_style(s_style *style);
void	ft_creat_victory(s_game *game);
void	ft_set_victoire(s_game *game);
int	ft_compteur(gpointer data);
char	*ft_time(int n);
char	*ft_itoa(int n);
#endif
