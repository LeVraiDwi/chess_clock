#include <wiringPi.h>
#include <stdio.h>
#include <pthread.h>

typedef struct	t_game
{
	pthread_t	*thread;
	int		player;
	unsigned int	game;
	unsigned int	pause;
	unsigned int	time[2];
	unsigned int	timeb[2];
	int		timer_state;
}		s_game;

void ft_read_button(void *data)
{
	s_game	*game;

	printf("test1\n");
	game = (s_game *)data;
	while (game->game)
	{
		if (digitalRead(0) == 0)
		{
			if (game->pause == 0)
			{
				game->player = 1;
			}
		}
		else if (digitalRead(2) == 0)
		{
			if (game->pause == 0)
			{
				game->player = -1;
			}
		}
		delay(20);
	}
}

void ft_init_wiring(void)
{
	wiringPiSetup();
	pinMode(0, INPUT);
	pinMode(2, INPUT);
}

int	main(void)
{
	s_game game;

	ft_init_wiring();
	pthread_create(game.thread, 0, (void *)ft_read_button, (void *)&game);
	while (1)
		printf("%i\n", game.player);
	return (0);
}

