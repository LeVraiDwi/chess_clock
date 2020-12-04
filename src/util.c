#include "clock_chest.h"

int		ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_int_str(char *str, int n)
{
	if (n / 10 != 0)
		ft_int_str(str++, n / 10);
	*str = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l;

	l = ft_intlen(n);
	if (!(str = malloc(sizeof(char) * l)))
		return (0);
	ft_int_str(str, n);
	return (str);
}

int	ft_strlen (char *str)
{
	int	i;

	i = 0;
	while (str++)
		i++;
	return (i);
}

char *ft_strcat(char *str, char *s)
{
	char	*new_str;
	int		l;

	l = ft_strlen(str) + ft_strlen(s) + 1;
	new_str = malloc(sizeof(char) * l);
	l = 0;
	while (str)
	{
		new_str[l++] = str++;
	}
	while (str)
	{
		new_str[l++] = s++;
	}
	return (new_str);
}
