#include "clock_chest.h"

void	ft_init_style(s_style *style)
{
	style->provider = 0;
	style->display = 0;
	style->screen = 0;
}

void	ft_set_style(s_game *game)
{
	s_style *style;

	style = &game->style;
	ft_init_style(style);
	style->provider = gtk_css_provider_new();
	style->display = gdk_display_get_default();
	style->screen = gdk_display_get_default_screen(style->display);
	gtk_style_context_add_provider_for_screen(style->screen, GTK_STYLE_PROVIDER(style->provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(style->provider), "style/style.css", 0);
}
