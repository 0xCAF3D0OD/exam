/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:18:20 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/22 21:19:47 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exam.h"
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!(str))
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int main(int ac, char **av)
{
	FILE *file;
	char *dessin;
	int	count;

	(void) file;
	(void) dessin;
	(void) av;
	if (ac != 2)
		return (ft_error("error: arguments\n"));
	if (!(file = fopen(av[1], 'r')))
		return (ft_error("error: operation file corrupted\n"));
	if (!())
	return (0);
}