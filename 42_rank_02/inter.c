/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:30:19 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/04/11 16:10:57 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check(char *str, char c, int i)
{
	int	j;

	j = i;
	while(j-- >= 0)
	{
		if (str[j] == c)
			return (0);
	}
	return (1);
}

void	ft_iter(char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	while (s1[++i])
	{
		if (ft_check(s1, s1[i], i) == 1)
		{
			j = -1;
			while (s2[++j])
			{
				if (s2[j] == s1[i])
				{
					write(1, &s1[i], 1);
					break ;
				}
			}
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_iter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}