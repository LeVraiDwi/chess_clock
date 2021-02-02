#ifndef CLOCK_CHEST_H
#	define	CLOCK_CHEST_H
#	include	<time.h>
#	include	<gtk/gtk.h>
#	include <stdlib.h>
#	include	<pthread.h>
#	define	TIMER_B "time_blanc"
#	define	TIMER_N "timer_noir"

typedef	struct	t_style
{
	GtkCssProvider	*provider;
	GdkDisplay	*display;
	GdkScreen	*screen;
}		s_style;

typedef struct	t_game
{
	GtkWidget	*window;
	GtkWidget	*window_custom;
	GtkWidget	*grid;
	GtkWidget	*grid_custom;
	GtkWidget	*button[6];
	GtkWidget	*menu_button;
	GtkWidget	*popover;
	GtkWidget	*label_custom[8];
	int		player;
	unsigned int	game;
	unsigned int	pause;
	unsigned int	time[2];
	unsigned int	timeb[2];
	int		timer_state;
	gdouble		start1;
	gdouble		start2;
	gdouble		player1;
	gdouble		player2;
	GTimer		*timer1;
	GTimer		*timer2;
	gdouble		tbonus[2];

	s_style		style;
}		s_game;
//timer.c
void	ft_creat_timer(s_game *game);
void	ft_add_tbonus(gdouble tbonus, GtkWidget *button, GTimer *timer, gdouble player);
void	ft_creat_grid_timer(s_game *game);
void	ft_init_timer(s_game *game);
int	ft_timer(gpointer data);
//button.c
void	ft_init_button(GtkWidget *button[]);
void	ft_creat_button(GtkWidget *button[]);
void	ft_creat_box_timer(s_game *game);
//game.c
void	ft_init_game(s_game *game);
void	ft_creat_game(s_game *game);
//event.c
void	ft_button_0(GtkWidget *objet, gpointer data);
void	ft_button_1(GtkWidget *objet, gpointer data);
void	ft_button_2(GtkWidget *objet, gpointer data);
void	ft_button_3(GtkWidget *objet, gpointer data);
void	ft_button_4(GtkWidget *objet, gpointer data);
void	ft_bullet_1(GtkWidget *objet, gpointer data);
void	ft_bullet_2(GtkWidget *objet, gpointer data);
void	ft_blitz_1(GtkWidget *objet, gpointer data);
void	ft_blitz_2(GtkWidget *objet, gpointer data);
void	ft_blitz_3(GtkWidget *objet, gpointer data);
void	ft_blitz_4(GtkWidget *objet, gpointer data);
void	ft_rapid_1(GtkWidget *objet, gpointer data);
void	ft_rapid_2(GtkWidget *objet, gpointer data);
void	ft_rapid_3(GtkWidget *objet, gpointer data);
void	ft_rapid_4(GtkWidget *objet, gpointer data);
void	ft_rapid_5(GtkWidget *objet, gpointer data);
void	ft_custom(GtkWidget *objet, gpointer data);
void	ft_minus_min_j1(GtkWidget *objet, gpointer data);
void	ft_minus_min_j2(GtkWidget *objet, gpointer data);
void	ft_minus_min_b2(GtkWidget *objet, gpointer data);
void	ft_minus_min_b1(GtkWidget *objet, gpointer data);
void	ft_minus_second_j1(GtkWidget *objet, gpointer data);
void	ft_minus_second_j2(GtkWidget *objet, gpointer data);
void	ft_minus_second_b2(GtkWidget *objet, gpointer data);
void	ft_minus_second_b1(GtkWidget *objet, gpointer data);
void	ft_plus_second_j1(GtkWidget *objet, gpointer data);
void	ft_plus_second_j2(GtkWidget *objet, gpointer data);
void	ft_plus_second_b1(GtkWidget *objet, gpointer data);
void	ft_plus_second_b2(GtkWidget *objet, gpointer data);
void	ft_plus_min_j1(GtkWidget *objet, gpointer data);
void	ft_plus_min_j2(GtkWidget *objet, gpointer data);
void	ft_plus_min_b1(GtkWidget *objet, gpointer data);
void	ft_plus_min_b2(GtkWidget *objet, gpointer data);
void	ft_leave_custom(GtkWidget *objet, gpointer data);
//menu.c
void	ft_signal_timer(s_game *game);
void	ft_creat_menu(s_game *game);
void	ft_menu(s_game *game, GtkWidget *grid);
void	ft_creat_custom(s_game *game, GtkWidget *grid);
//style.c
void	ft_set_style(s_game *game);
void	ft_init_style(s_style *style);
//util.c
char	*ft_time(int n);
char	*ft_itoa(int n);
#endif
