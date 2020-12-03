#include "clock_chest.h"

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