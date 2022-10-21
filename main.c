#include "get_next_line.h"

int main(void)
{
	char	*temp;
	int	fd;
	int i = 0;

	fd = open("main.c", O_RDONLY);

	while(i < 2)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		printf("%s", temp);
		free(temp);
		i++;
	}
	return (0);
}
