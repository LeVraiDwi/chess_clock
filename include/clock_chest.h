#ifndef CLOCK_CHEST_H
#	define	CLOCK_CHEST_H
#	include	<time.h>
#	include	<gtk/gtk.h>
#	include <stdlib.h>

typedef struct	t_button
{
	GtkWidget	*bu10;
	GtkWidget	*bu12;
	GtkWidget	*bl30;
	GtkWidget	*bl32;
	GtkWidget	*bl50;
	GtkWidget	*bl53;
	GtkWidget	*r100;
	GtkWidget	*r105;
	GtkWidget	*r1510;
	GtkWidget	*r300;
	GtkWidget	*r3020;
	GtkWidget	*leave;
}		s_button;
void	ft_timer(long j1sec, long j2sec);
#endif

