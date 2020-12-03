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
}		s_game;
void	ft_timer(long j1sec, long j2sec);
#endif

