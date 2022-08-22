#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int		WIDTH;
int		HEIGHT;
char	BACKGROUND_CHAR;
char	**PAINT;

int	ft_close(FILE *fd, int errcode)
{
	if (errcode == 1)
		write(1, "Error: argument\n", 16);
	else if (errcode == 2 && (errcode = 1)) // convert errcode to 1 after first check
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

int	main(int argc, char **argv)
{
	FILE	*fd;
	int		scan_ret;
	float	distance;
	char	c_character;
	float	x_center;
	float	y_center;
	float	radius;
	char	character;

	fd = NULL;
	if (argc != 2)
		return (ft_close(fd, 1)); // Error: argument
	if ((fd = fopen(argv[1], "r")))
	{
		if ((scan_ret = fscanf(fd, "%d %d %c", &WIDTH, &HEIGHT, &BACKGROUND_CHAR)) == 3) // first line of file
		{
			if (WIDTH > 0 && WIDTH <= 300 && HEIGHT > 0 && HEIGHT <= 300)
			{
				PAINT = malloc(sizeof(char *) * HEIGHT);
				for (int i = 0; i < HEIGHT; i++)
				{
					PAINT[i] = malloc(sizeof(char) * WIDTH);
					memset(PAINT[i], BACKGROUND_CHAR, WIDTH); // init background
				}
				while (1)
				{
					scan_ret = fscanf(fd, "\n%c %f %f %f %c", &c_character, &x_center, &y_center, &radius, &character);
					if (scan_ret == -1)
						return (ft_close(fd, 0)); // success
					else if (scan_ret != 5 || radius <= 0 || (c_character != 'c' && c_character != 'C'))
						break ; // Error: Operation file corrupted
					for (int y = 0; y < HEIGHT; y++)
					{
						for (int x = 0; x < WIDTH; x++)
						{
							distance = sqrt(powf(x - x_center, 2) + powf(y - y_center, 2));
							if (distance <= radius)
								if (c_character == 'C' || (distance + 1 > radius && c_character == 'c'))
									PAINT[y][x] = character;
						}
					}
				}
			}
		}
	}
	return (ft_close(fd, 2));
}