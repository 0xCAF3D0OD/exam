#include <unistd.h>
#include <stdio.h>


void ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (checker(s1, s1[i], i) == 1)
	{
		write(1, &s1[i], 1);
		i++;
	}
	i = 0;
 	j = 0
	while (checker(s2, s2[i], j) == 1)
	{
		j = 0;
		while (checker(s1, s2[j], j) == 1)
		{
			write(1, &s2[j], 1);
			j++;
		}	
	}

}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2])
	return (0)
}
