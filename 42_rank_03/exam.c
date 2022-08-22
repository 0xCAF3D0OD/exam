/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:08:00 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/22 21:59:31 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exam.h"

int	ft_free(FILE *file, char *draw)
{
	fclose(file);
	if (draw)
		free(draw);
	return (1);
}

int	ft_strlen(char *str)
{
	int i = 0;

	if (!(str))
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *get_zone(t_zone *zone, FILE *file)
{
	char *array;
	int i;

	if ((i = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->bg)) != 3)
		return (NULL);
	if ((zone->height > 300 || zone->height < 0) || (zone->width > 300 || zone->width < 0))
		return (NULL);
	if (!(array = (char *) malloc(sizeof(t_zone *) * (zone->height * zone->width))))
		return (NULL);
	i = 0;
	while (i < zone->height * zone->width)
	{
		array[i] = zone->bg;
		i++;
	}
	return (array);
}

int	ft_fail(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int main(int ac, char **av)
{
	t_zone zone;
	FILE *file;
	char *draw;
	
	(void) zone;	
	if (ac != 2)
		return (ft_fail("error: arguments\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_fail("error: operation file corrupted\n"));
	if (!(draw = get_zone(&zone, file)))
		return (ft_free(file, NULL) && ft_fail("error: operation file corrupted\n"));
	if (!(drawing(file, &draw, &zone)))
		return (ft_free(file, draw) && ft_fail("error: operation file corrupted\n")) 
	return (0);
}