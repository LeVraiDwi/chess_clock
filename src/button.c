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
	button[14] = 0;
	button[15] = 0;
	button[16] = 0;
	button[17] = 0;
}

void	ft_creat_button(GtkWidget *button[])
{
	GtkStyleContext	*context;

	button[0] = gtk_button_new_with_label("Bullet\n1 + 0");
	context = gtk_widget_get_style_context(button[0]);
	gtk_style_context_add_class(context, "bullet");
	button[1] = gtk_button_new_with_label("Bullet\n2 + 1");
	context = gtk_widget_get_style_context(button[1]);
	gtk_style_context_add_class(context, "bullet");
	button[2] = gtk_button_new_with_label("Blitz\n3 + 0");
	context = gtk_widget_get_style_context(button[2]);
	gtk_style_context_add_class(context, "blitz");
	button[3] = gtk_button_new_with_label("Blitz\n3 + 2");
	context = gtk_widget_get_style_context(button[3]);
	gtk_style_context_add_class(context, "blitz");
	button[4] = gtk_button_new_with_label("Blitz\n5 + 0");
	context = gtk_widget_get_style_context(button[4]);
	gtk_style_context_add_class(context, "blitz");
	button[5] = gtk_button_new_with_label("Blitz\n5 + 3");
	context = gtk_widget_get_style_context(button[5]);
	gtk_style_context_add_class(context, "blitz");
	button[6] = gtk_button_new_with_label("Rapid\n10 + 0");
	context = gtk_widget_get_style_context(button[6]);
	gtk_style_context_add_class(context, "rapid");
	button[7] = gtk_button_new_with_label("Rapid\n10 + 5");
	context = gtk_widget_get_style_context(button[7]);
	gtk_style_context_add_class(context, "rapid");
	button[8] = gtk_button_new_with_label("Rapid\n15 + 10");
	context = gtk_widget_get_style_context(button[8]);
	gtk_style_context_add_class(context, "rapid");
	button[9] = gtk_button_new_with_label("Rapid\n30 + 0");
	context = gtk_widget_get_style_context(button[9]);
	gtk_style_context_add_class(context, "rapid");
	button[10] = gtk_button_new_with_label("Rapid\n30 + 20");
	context = gtk_widget_get_style_context(button[10]);
	gtk_style_context_add_class(context, "rapid");
	button[11] = gtk_button_new_with_label("Custom...");
	context = gtk_widget_get_style_context(button[11]);
	gtk_style_context_add_class(context, "custom");
	button[12] = gtk_button_new_with_label("Leave");
	context = gtk_widget_get_style_context(button[12]);
	gtk_style_context_add_class(context, "leave");
	button[13] = gtk_button_new_with_label("Leave");
	context = gtk_widget_get_style_context(button[13]);
	gtk_style_context_add_class(context, "leave");
	button[14] = gtk_button_new_with_label("pause/play");
	context = gtk_widget_get_style_context(button[14]);
	gtk_style_context_add_class(context, "play");
	button[15] = gtk_button_new_with_label("timer1");
	context = gtk_widget_get_style_context(button[15]);
	gtk_style_context_add_class(context, "timer1");
	button[16] = gtk_button_new_with_label("timer2");
	context = gtk_widget_get_style_context(button[16]);
	gtk_style_context_add_class(context, "timer2");
	button[17] = gtk_button_new_with_label("timer2");
	context = gtk_widget_get_style_context(button[17]);
	gtk_style_context_add_class(context, "leave");
}

void	ft_affichage_button(s_game *game)
{
	//button pour main menu
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
	g_object_ref((gpointer *)game->hbox);
	gtk_container_add(GTK_CONTAINER(game->window), game->hbox);
}

void	ft_creat_box_timer(s_game *game)
{
	gtk_box_pack_start(GTK_BOX(game->hbox_timer[0]), game->button[15], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox_timer[0]), game->button[16], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox_timer), game->hbox_timer[0], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox_timer[1]), game->button[14], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox_timer[1]), game->button[13], TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox_timer), game->hbox_timer[1], FALSE, TRUE, 0);
	g_object_ref((gpointer *)game->vbox_timer);
}
