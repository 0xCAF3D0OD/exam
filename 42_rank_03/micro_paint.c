/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:48 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/22 22:01:58 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exam.h"

int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int free_all(FILE *file, char *draw)
{
	fclose(file);
	if (draw)
		free(draw);
	return (1);
}

void print_draw(char *draw, t_zone *zone)
{
	int i = 0;

	while (i < zone->height)
	{
		write(1, draw + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

/*	
	is_rec (int y, int x, t_list tmp)
	float check = 1.00000000;

	si (comparaison en x et tmp->x ou y et tmp->y rend qlq chose)
		retourner 0
*/

int is_rec(float y, float x, t_list *tmp)
{
	float check = 1.00000000;
	if ((x < tmp->x) || (tmp->x + tmp->width < x) || (y < tmp->y) || (tmp->y + tmp->height < y))
		return (0);
	if (((x - tmp->x) < check) || ((tmp->x + tmp->width) - x < check) || ((y - tmp->y) < check) || ((tmp->y + tmp->height) - y < check))
		return (2);
	return (1);
}

/*	
	void get_draw (char **draw de fonction get_zone, t_list tmp, struct zone)
	int x, y, rec

	y est a 0
	tant que (y plus petit que struct->haut.)
		x = 0;
		tant que (x < struct.larg)
			rec = is_rec(x, y, tmp)
			si ((tmp->type == 'r' et rec == 2) ou (tmp->type == 'R' et rec == qelque chose))
				(*draw)[(y * struct zone.larg.) + x] = tmp->color;
*/

void get_draw(char **draw, t_list *tmp, t_zone *zone)
{
	int x, y, rec;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			rec = is_rec(y, x, tmp);
			if ((tmp->type == 'r' && rec == 2) || (tmp->type == 'R' && rec))
			(*draw)[(y * zone->width) + x] = tmp->color;
			x++;
		}
		y++;
	}
}

/*	int drawing (fichier fopen, fichier obtenu de getzone, struct zone)
	struct list
	int count

	tant que val_retour de count = fscanf(fichier fopen, "char &struct.type, float &struct.x, float &struct.y, float &struct.larg., float &struct.haut., char &cstruct.ouleurs\n",) == 6)
		si (struct.larg < 0 et struct.haut < 0 et (struct.type different de 'r' ou 'R')
			get_draw(draw, &struct, zone)
	si count est different de -1 on retourn 0
	autrement on retourn 1 
*/

int drawing(FILE *file, char **draw, t_zone *zone)
{
	t_list tmp;
	int count;

	while ((count = fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.color)) == 6)
	{
		if (tmp.width <= 0.00000000 && tmp.height <= 0.00000000 && (tmp.type != 'r' || tmp.type != 'R'))
			return (0);
		get_draw(draw, &tmp, zone);
	}
	if (count != (-1))
		return (0);
	return (1);
}

/*	char *get_zone (fichier => fopen, struct zone(larg. haut. char *bg))
	char *array
	int i

	3 conditions:
		1.	si (i = fscanf(fichier, haut., larg., char *bg)) != 3 => on retourne NULL
		2.	si larg. =	>300
						<=0
			ou si haut. = >300
						<=0
			RETOURNER (NULL)
		3.	si resultat de malloc(char *) * (larg. * haut.) passe a array == NULL => retourner NULL

	autrement
		boucler (i plus petit que (larg. * hauteur))
			passer valeur char bg => array[i]
	retourner (array)
*/

char *get_zone(FILE *file, t_zone *zone)
{
	char *array;
	int i = 0;

	if ((i = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->bg)) != 3)
		return (NULL);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (NULL);
	if (!(array = (char *)malloc(sizeof(char) * (zone->width * zone->height))))
		return (NULL);
	i = 0;
	while (i < zone->width * zone->height)
	{
		array[i] = zone->bg;
		i++;
	}
	return (array);
}

int fail(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

/*
	int main(ac av)
	variable FILE *pointer
	string *draw
	struct zone

	si argc different de 2 afficher "error arguments"
	si file = fopen(argv[1], "r") rend rien => afficher "Error: Operation file corrupted\n"
	si draw = get_zone(fichier fopen, &zone) rend rien => renvoyer free_all(fichier fopen, char *str = NULL) et afficher "Error: Operation file corrupted\n"
	si fonction drawing(fichier fopen, &draw, &zone) rend rien => renvoyer free_all(fichier fopen, char *draw) et afficher "Error: Operation file corrupted\n"
	print_draw(draw, &zone)
	free_all(fichier fopen, draw)
	on retourne (0)

*/
int main(int argc, char **argv)
{
	FILE *file;
	char *draw;
	t_zone zone;

	if (argc != 2)
		return (fail("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (fail("Error: Operation file corrupted\n"));
	if (!(draw = get_zone(file, &zone)))
		return (free_all(file, NULL) && fail("Error: Operation file corrupted\n"));
	if (!(drawing(file, &draw, &zone)))
		return (free_all(file, draw) && fail("Error: Operation file corrupted\n"));
	print_draw(draw, &zone);
	free_all(file, draw);
	return (0);
}