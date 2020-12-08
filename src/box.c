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
	vbox[0] = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	while (i < 4)
	{
		vbox[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
		i++;
	}
}

void	ft_creat_hbox(GtkWidget *hbox[])
{
	hbox[0] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	hbox[1] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_set_homogeneous(GTK_BOX(hbox[1]), 1);
}
