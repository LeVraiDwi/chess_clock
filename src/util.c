#include "clock_chest.h"

int		ft_intlen(int n)
{
	int	i;

	i = 1;
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
	if (!(str = malloc(sizeof(char) * l + 1)))
		return (0);
	ft_int_str(str, n);
	str[l] = 0;
	return (str);
}

int	ft_strlen (char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char *ft_strcat(char *str, char *s)
{
	char	*new_str;
	int		l;

	l = 0;
	if (ft_strlen(str) < 2)
		l += 1;
	if (ft_strlen(s) < 2)
		l += 1;
	l += ft_strlen(str) + ft_strlen(s) + 2;
	new_str = malloc(sizeof(char) * l);
	l = 0;
	if (ft_strlen(str) < 2)
		new_str[l++] = '0';
	while (*str)
	{
		new_str[l++] = *str++;
	}
	new_str[l++] = ':';
	if (ft_strlen(s) < 2)
		new_str[l++] = '0';
	while (*s)
	{
		new_str[l++] = *s++;
	}
	str[l] =  0;
	return (new_str);
}

char	*ft_time(int n)
{
	char	*str1;
	char	*str2;
	char	*tmp;

	str1 = ft_itoa(n / 60);
	str2 = ft_itoa(n % 60);
	tmp = ft_strcat(str1, str2);
	tmp[ft_strlen(tmp ) - 1] = '\0';
	printf("%s\n",tmp);
	free(str1);
	free(str2);
	return (tmp);
}
