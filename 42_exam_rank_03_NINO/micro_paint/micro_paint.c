#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int		WIDTH;
int		HEIGHT;
char	BACKGROUND_CHAR;
char	**PAINT;

typedef struct s_rec
{
	char	r_character;
	float	x_topleft;
	float	y_topleft;
	float	width;
	float	height;
	char	character;
}	t_rec;

int	ft_close(FILE *fd, int errcode)
{
	if (errcode == 1)
		write(1, "Error: argument\n", 16);
	else if (errcode == 2 && (errcode = 1))
		write(1, "Error: Operation file corrupted\n", 32);
	else
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			write(1, PAINT[i], WIDTH);
			write(1, "\n", 1);
		}	
	}
	if (fd)
		fclose(fd);
	return (errcode);
}

int	in_rect(float y, float x, t_rec rec)
{
	if (x < rec.x_topleft || x > rec.x_topleft + rec.width || y < rec.y_topleft || y > rec.y_topleft + rec.height)
		return (0);
	if (x - rec.x_topleft < 1 || 1 > rec.x_topleft + rec.width - x || y - rec.y_topleft < 1 || 1 > rec.y_topleft + rec.height - y)
		return (1);
	return (2);
}

int	main(int argc, char **argv)
{
	t_rec	rec;
	FILE	*fd;
	int		scan_ret;
	int		inside;

	fd = NULL;
	if (argc != 2)
		return (ft_close(fd, 1));
	if ((fd = fopen(argv[1], "r")))
	{
		if ((scan_ret = fscanf(fd, "%d %d %c", &WIDTH, &HEIGHT, &BACKGROUND_CHAR)) == 3)
		{
			if (WIDTH > 0 && WIDTH <= 300 && HEIGHT > 0 && HEIGHT <= 300)
			{
				PAINT = malloc(sizeof(char *) * HEIGHT);
				for (int i = 0; i < HEIGHT; i++)
				{
					PAINT[i] = malloc(sizeof(char) * WIDTH);
					memset(PAINT[i], BACKGROUND_CHAR, WIDTH);
				}
				while (1)
				{
					scan_ret = fscanf(fd, "\n%c %f %f %f %f %c", &rec.r_character, &rec.x_topleft, &rec.y_topleft, &rec.width, &rec.height, &rec.character);
					if (scan_ret == -1)
						return (ft_close(fd, 0));
					if (scan_ret != 6 || rec.width <= 0 || rec.height <= 0 || (rec.r_character != 'r' && rec.r_character != 'R'))
						break ;
					for (int y = 0; y < HEIGHT; y++)
					{
						for (int x = 0; x < WIDTH; x++)
						{
							inside = in_rect(y, x, rec);
							if (inside == 1 || (inside > 0 && rec.r_character == 'R'))
								PAINT[y][x] = rec.character;
						}
					}
				}
			}
		}
	}
	return (ft_close(fd, 2));
}