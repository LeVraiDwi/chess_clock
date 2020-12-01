#include "clock_chest.h"

void	ft_timer(long j1sec, long j2sec)
{
	int	start;
	
	start = 1;
	while (j1sec != 0 && j2sec != 0 && start)
	{
		while (start == 1 && j1sec)
		{
			printf("j1 seconde : %li\n", j1sec);
			sleep(1);
			j1sec--;
		}
		while (start == 2 && j2sec)
		{
			sleep(1000);
			j2sec--;
		}
	}
}
