#include "clock_chest.h"

int	ft_intlen(int n)
{
	int	l;

	l = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
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

gchar *ft_strcat(char *str, char *s)
{
	gchar	*new_str;
	int		l;

	l = 4;
	l += ft_strlen(str);
	new_str = malloc(sizeof(char) * l + 1);
	l = 0;
	if (ft_strlen(str) == 1)
		new_str[l++] = '0';
	while (*str)
	{
		new_str[l++] = *str++;
	}
	new_str[l++] = ':';
	if (ft_strlen(s) == 1)
		new_str[l++] = '0';
	while (*s)
	{
		new_str[l++] = *s++;
	}
	new_str[l] =  0;
	return (new_str);
}

gchar	*ft_time(int n)
{
	char	*str1;
	char	*str2;
	gchar	*tmp;
	gchar	*utf8;

	str1 = ft_itoa(n / 60);
	str2 = ft_itoa(n % 60);
	tmp = ft_strcat(str1, str2);
	tmp[ft_strlen(tmp)] = 0;
	printf("%s\n",tmp);
	utf8 = g_locale_to_utf8(tmp, -1, 0, 0, 0);
	free(str1);
	free(str2);
	free(tmp);
	return (utf8);
}
