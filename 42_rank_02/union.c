#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_check_char(char *str, char c, int index)
{
	int		i;

	i = index;
	while (i-- >= 0)
	{
		if (str[i] == c)
			return (0);
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int		i;
	int		len;

	i = 0;
	while (s1[i])
	{
		if (ft_check_char(s1, s1[i], i) == 1)
			write(1, &s1[i], 1);
		i++;
	}
	len = i;
	i = -1;
	while (s2[++i])
	{
		if (ft_check_char(s2, s2[i], i) == 1)
		{
			if (ft_check_char(s1, s2[i], len) == 1)
				write(1, &s2[i], 1);
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
