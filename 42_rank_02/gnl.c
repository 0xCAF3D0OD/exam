#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(char *str, char c)
{
	int	i;
	char *s;

	i = 0;
	while (str[i])
		i++;
	s = (char *) malloc(i + 2);
	i = 0;
	while(str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = c;
	s[i + 1] = 0;
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	char buff;
	char *line;
	int	ret;
	int i;

	if (fd < 0)
		return (NULL);
	line = (char *)malloc(1);
	line[0] = '\0';
	while((ret = read(fd, &buff, 1)) > 0)
	{
		line = ft_strjoin(line, buff);
		if (buff == '\n')
			break ;
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0 || ret == -1)
	{
		free (line);
		line = NULL;
	}
	return (line);
}

int	main(void)
{
	char *buffer;

	buffer = get_next_line(0);
	while (buffer)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(0);
	}
	return (0);
}
