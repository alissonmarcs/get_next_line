#include "../get_next_line.h"

#include <fcntl.h> // to acess open()
#include <stdio.h>

int main()
{
	int file1;
	char *line;

	file1 = open("file1.txt", O_RDONLY);

	line = get_next_line(file1);
	printf("%s", line);
	free(line);

	line = get_next_line(file1);
	printf("%s", line);
	free(line);

	close(file1);
}
