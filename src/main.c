#include "clock_chest.h"


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
	button[11] = gtk_button_new_with_label("Leave");
}

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


void	ft_affichage_button(GtkWidget *box, GtkWidget *button[])
{
	int	i;

	i = 0;
	while (button[i])
	{
		gtk_box_pack_end(GTK_BOX(box), button[i], TRUE, FALSE, 0);
		i++;
	}	
}

int	main(int argc, char **argv)
{
	GtkWidget	*window;
	GtkWidget	*button[14];
	GtkWidget	*box;	
	//s_button	button;
	//const gchar	*strlabel;
	int	j1sec;

	window = 0;
	j1sec = 60;
	//initialisation
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//parametre fenetre
	gtk_window_set_title(GTK_WINDOW(window), "ChestClock AKA CC");
	gtk_window_set_default_size(GTK_WINDOW(window), 260, 240);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	//fulscreen event
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_fullscreen(GTK_WINDOW(window));
	//label
	box = gtk_hbox_new(1, 0);
	ft_init_button(button);
	ft_creat_button(button);
	ft_affichage_button(box, button);
	gtk_container_add(GTK_CONTAINER(window), box);
	//strlabel = get_label_get_label(GTK_LABEL(label));
	//affichage
	gtk_widget_show_all(window);
	//ft_timer(j1sec, 60);
	//le main
	gtk_main();
	return 1;
}

